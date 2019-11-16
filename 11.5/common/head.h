/*************************************************************************
	> File Name: head.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 18时34分18秒
 ************************************************************************/

#ifndef _HEAD_H
#define _HEAD_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/shm.h>
#include <sys/epoll.h>
#include <pwd.h>
#include <pthread.h>
#include <sys/epoll.h>

typedef struct Node {
    struct sockaddr_in addr;
    struct Node *next;
    char name[20];
    int ans;
} Node, *LinkedList;

typedef struct Data {
    int type;
    int bodyLength;
    char name[20];
} Data;

typedef struct User {
    struct sockaddr_in addr;
    char name[20];
} User;

#ifdef _DEBUG
#define D(fmt, args...) printf(fmt, ##args) 
#else 
#define D(fmt, args...) 
#endif

#endif
