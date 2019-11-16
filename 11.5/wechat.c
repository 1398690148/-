/*************************************************************************
	> File Name: wechat.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 19时06分02秒
 ************************************************************************/

#include "common/head.h"
#include "common/common.h"
#include "common/linklist.h"

#define P(frm, color, arg...) { \
    printf("\033[;%dm" frm "\033[0m", color, ##arg); \
}

#ifndef MAX_LEN
#define MAX_LEN 256
#endif
#define EPOLL_SIZE  1000

char value[50] = {0};
char name[20] = {0};
int port, ins;
char path[] = "./wechat.conf";
LinkedList *linkedlist;
int *sum;
pthread_mutex_t mutex;

void *print(void *arg) {
    LinkedList *p = (LinkedList *)arg;
    while (1) {
        LinkedList q;
        for (int i = 0; i < ins; i++) {
            q = p[i];
            sleep(10);
            while (q->next != NULL) {
                if (is_Online(q->next->addr, name) == -1) {
                    q->next->ans++;
                    continue;
                    if (q->next->ans == 3) {
                        P("[Delete]", 31);
                        printf(" %s\n", q->next->name);
                        delete_node(q, q->next);
                        break;
                    }
                } else {
                    q->next->ans = 0;
                }
                q = q->next;
            }
        }
    }
    return NULL;
}

void CaluserTable(LinkedList exchangelist, LinkedList *head, Data *user) {
    LinkedList *p = head;
    for (int i = 0; i < ins; i++) {
        LinkedList q = p[i];
        while (q->next != NULL) {
            Node *node = init(q->addr, q->name);
            Insert(exchangelist, node);
            user->bodyLength++;
            q = q->next;
        }
    }
    return ;
}

void SendUserTable(LinkedList exchangelist, LinkedList *head, Data *user) {
    LinkedList *p = head;
    for (int i = 0; i < ins; i++) {
        LinkedList q = head[i];
        while (q->next != NULL) {
            if (sendMsg(q->next->addr, user, exchangelist)) {
                q->ans = 0;
                P("交换用户信息表成功\n", 35);
            } else {
                q->ans += 1;
                P("交换用户信息表失败\n", 35);
            }
            q = q->next;
        }
    }
}

void *exchange_user(void *arg) {
    LinkedList *p = (LinkedList *)arg;
    while (1) {
        sleep(1);
        Data *user = (Data *)malloc(sizeof(Data));
        LinkedList exchangelist = (LinkedList)malloc(sizeof(Node));
        struct sockaddr_in initaddr;
        initaddr.sin_family = AF_INET;
        initaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
        initaddr.sin_port = htons(port);
        Node *node = init(initaddr, "init");
        exchangelist = node;
        CaluserTable(exchangelist, p, user);
        user->type = 2;
        strcpy(user->name, name);
        SendUserTable(exchangelist, (LinkedList *)arg, user);
        free(user);
        free(exchangelist);
    }
    return NULL;
}

/*int addUserTable(LinkedList *l, char *name) {
    if (check_online(l, p->content, ins)) {
        Node *twoNode = (Node *)malloc(sizeof(Node));
        twoNode->addr = p->content;
        twoNode->addr.sin_port = htons(port);
        twoNode->next = NULL;
        twoNode->ans = 0;
        strcpy(twoNode->name, name);
        int sub = find_min(sum, ins);
        Insert(linkedlist[sub], twoNode);
        sum[sub]++;
    }
}*/

void *client_listen() {
    int server_listen, sockfd;

    if ((server_listen = socket_create(port)) < 0) {
        perror("socker_create()");
        return NULL;
    }
    while (1) {
        P("[Listen]", 34);
        printf(" Listening...\n");
        struct sockaddr_in client;
        socklen_t s_len = sizeof(client);
        fflush(stdout);
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &s_len)) < 0) {
            perror("accept()");
            close(sockfd);
            continue;
        }
        P("[Accept]", 36);
        printf(" Accept...\n");
        fd_set set;
        FD_ZERO(&set);
        FD_SET(sockfd, &set);
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 10000;
        Data *data = (Data *)malloc(sizeof(Data));
        if (select(sockfd + 1, &set, NULL, NULL, &tv) > 0) {
            if (FD_ISSET(sockfd, &set)) {
                recv(sockfd, data, sizeof(Data), 0);
                if (data->type == 0) {
                    P("[Login] ", 32);
                    printf("logname = %s : %s Login\n", data->name, inet_ntoa(client.sin_addr));
                    Data *returnData = (Data *)malloc(sizeof(Data));
                    returnData->type = 0;
                    returnData->bodyLength = 0;
                    strcpy(returnData->name, name);
                    send(sockfd, returnData, sizeof(returnData), 0);
                } else if (data->type == 1) {
                    P("[Heart Jump]\n", 32);
                    continue;
                } /*else if (data->type == 2) {
                    P("[Exchange User Table]　%s\n", 32, data->name);
                    int flag = 0;
                    User *userTable = (User *)malloc(sizeof(User) * 100);
                    while (recv(sockfd, userTable, sizeof(userTable), 0) != 0) {
                        int size = recv(sockfd, userTable, sizeof(userTable), 0);
                        int recvSize = data->bodyLength * sizeof(User);
                        if (size < 0) break;
                        if (size == 0 && size != recvSize) {
                            printf("错误的交换报文段\n");
                            break;
                        }
                        if (size == recvSize) {
                            flag = 1;
                            break;
                        }
                        continue;
                    }
                    for (int i = 0, I = sizeof(userTable); i < I && flag; i++) {
                        printf("%u %s\n", userTable[i].addr.sin_addr.s_addr, userTable[i].name);
                    }
                }*/
                if (check_online(linkedlist, client, ins)) {
                    Node *twoNode = (Node *)malloc(sizeof(Node));
                    twoNode->addr = client;
                    twoNode->addr.sin_port = htons(port);
                    twoNode->next = NULL;
                    twoNode->ans = 0;
                    strcpy(twoNode->name, data->name);
                    int sub = find_min(sum, ins);
                    Insert(linkedlist[sub], twoNode);
                    sum[sub]++;
                }
                close(sockfd);
            } else {
                close(sockfd);
                continue;
            }
        } else {
            close(sockfd);
        }
    }
    return NULL;
}

/*void *chat(void *arg) { 
	LinkedList *p = (LinkedList *)arg;

    int fd = 0;
    int len = 0;
    int nfds = 0;
    int index = 0;
    char buf[MAX_LEN] = {0};
    struct epoll_event ev;
    struct epoll_event event[EPOLL_SIZE];

    if(-1 == (fd = epoll_create(EPOLL_SIZE))){
        perror("create epoll object error:");
        return NULL;
    }
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = STDIN_FILENO;
    epoll_ctl(fd,EPOLL_CTL_ADD,STDIN_FILENO,&ev);
    
    while(1){
        nfds = epoll_wait(fd, event, 1000, -1);
        if(nfds == -1){
            perror("epoll_wait:");
            return  NULL;
        }
        for(index = 0; index < nfds; index++){
            for (int i = 0; i < ins; i++) {
                    if(event[index].events == EPOLLIN){
                        len = read(event[index].data.fd, buf, sizeof(buf));
                        LinkedList *p = (LinkedList *)arg;
                        for (int i = 0; i < ins; i++) {
                            while (p[i]->next != NULL) {

                            }
                        }
                        buf[len] = '\0';
                    } else if (event[index].events == EPOLLOUT) {
                        int sockfd_w = event[index].data.fd;
                        write(fd, buf, sizeof(buf));
                        ev.data.fd = sockfd_w;
                        ev.events = EPOLLIN | EPOLLET;
                        epoll_ctl(fd, EPOLL_CTL_MOD, sockfd_w, &ev);
                    }
                }
            } 
        }    
    return  EXIT_SUCCESS;
}*/

int main() {
    get_value(path, "name", name);    
    port = atoi(get_value(path, "listenport", value));
    ins = atoi(get_value(path, "ins", value));    
    unsigned int s, f;
    s = ntohl(inet_addr(get_value(path, "startip", value))); 
    f = ntohl(inet_addr(get_value(path, "endip", value))); 
   
    linkedlist = (LinkedList *)malloc(sizeof(LinkedList) * ins);
    sum = (int *)malloc(sizeof(int) * ins);
    
    struct sockaddr_in initaddr;
    initaddr.sin_family = AF_INET;
    initaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    initaddr.sin_port = htons(port);
    
    for (int i = 0; i < ins; i++) {
        Node *node = init(initaddr, "init");
        linkedlist[i] = node;
    }
    
    pthread_t listen;
    pthread_create(&listen, NULL, client_listen, NULL);

    for (int i = s; i <= f; i++) {
        if ((i & 255) == 255 || (i << 24) == 0) continue;
        initaddr.sin_addr.s_addr = htonl(i);
        Data *tmp = (Data *)malloc(sizeof(Data));
        tmp->type = 0;
        tmp->bodyLength = 0;
        strcpy(tmp->name, name);
        if (shake_hand(initaddr, tmp) == 1) {
            Node *newNode = init(initaddr, tmp->name);
            int sub = find_min(sum, ins);
            Insert(linkedlist[sub], newNode);
            sum[sub]++;
        }
    }
    //监测是否下线
    pthread_t work;
    pthread_create(&work, NULL, print, (void *)linkedlist);
    //交换用户信息表
    pthread_t change_list;
    pthread_create(&change_list, NULL, exchange_user, (void *)linkedlist);
    //发送消息
    /*pthread_t epoolwork;
    pthread_create(&epoolwork, NULL, chat, (void *)linkedlist);*/
    //监听是否有用户登录
    //client_listen();
    while (1) {
        sleep(3);
    }
    return 0;
}
