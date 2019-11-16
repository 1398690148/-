/*************************************************************************
	> File Name: linklist.c
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 18时59分40秒
 ************************************************************************/

#include "linklist.h"

Node *init(struct sockaddr_in initaddr, char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->addr = initaddr;
    newNode->ans = 0;
    strcpy(newNode->name, name);
    return newNode;
}

int Insert(LinkedList head, Node *node) {
    if (head == NULL) {
        head = node;
        return 0;
    }
    Node *p = head;
    while (p->next != NULL) p = p->next;
    p->next = node;
    return 0;
}


void delete_node(LinkedList head, Node *node) {
    LinkedList l = head, q;
    while (l->next) {
        if (l->next == node) {
            q = l->next;
            l->next = node->next;
            free(q);
            return ;
        }
        l = l->next;
    }
    return ;
}

void output(LinkedList l) {
    LinkedList p = l;
    while (p->next != NULL) {
        printf("%s : %s", inet_ntoa(p->next->addr.sin_addr), p->name);
        p = p->next;
    }
    return ;

}
