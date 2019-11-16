/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 18时35分42秒
 ************************************************************************/
#include "head.h"
#ifndef _COMMON_H
#define _COMMON_H

char *get_value(char *path, const char *key, char * const ans);

int socket_create(int port);

int socket_();

int shake_hand(struct sockaddr_in host, Data *msg);

int find_min(int *substrm, int ins);

int check_online(LinkedList *head, struct sockaddr_in client, int ins);

int is_Online(struct sockaddr_in client, char *name);

int sendMsg(struct sockaddr_in client, Data *msg, LinkedList exchangelist);

#endif
