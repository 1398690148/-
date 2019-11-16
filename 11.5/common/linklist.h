/*************************************************************************
	> File Name: linklist.h
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 18时58分17秒
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "head.h"

Node *init(struct sockaddr_in initaddr, char *name);

int Insert(LinkedList head, Node *node);

void delete_node(LinkedList head, Node *node);

void output(LinkedList l);
#endif
