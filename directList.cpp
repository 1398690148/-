/*************************************************************************
    > File Name: directList.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月17日 星期四 20时52分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node *pre, *next;
} Node, *LinkList;

Node *init(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = val;
	node->pre = node->next = NULL;
	return node;
}

Node *insert(LinkList head, int index, int val) {
	Node *p;
	if (head == NULL) {
		if (index != 0) return NULL;
		head = init(val);
		return head;
	}
	p = head;
	int count = 0;
	while (p && count < index - 1) {
		count++;
		p = p->next;
	}
	Node *node = init(val);
	if (p->next == NULL) {
		node->next = p->next;
		p->next = node;
		node->pre = p;
	} else {
		node->next = p->next;
		p->next->pre = node;
		p->next = node;
		node->pre = p;
	}
	return head;
}


void clear(LinkList list) {
	if (list == NULL) return ;
	Node *p = list, *q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	free(list);
	return ;
}

void output(LinkList head) {
	Node *p = head, *q;
	while (p != NULL) {
		printf("%d ", p->data);
		q = p;
		p = p->next;
	}
	printf("\n");
	while (q != NULL) {
		printf("%d ", q->data);
		q = q->pre;
	}
}

int main() {
	srand(time(0));
	LinkList list = NULL;
	#define MAX_N 20
	for (int i = 0; i < MAX_N; i++) {
		list = insert(list, 0, i);
	}
	output(list);
	return 0;
}

