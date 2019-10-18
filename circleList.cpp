/*************************************************************************
    > File Name: circleList.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月17日 星期四 20时25分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node, *LinkList;

Node *init(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = val;
	node->next = node;
	return node;
}

LinkList insert(LinkList head, Node *node, int ind) {
	if (head == NULL) {
		if (ind != 0) return NULL;
		head = node;
		head->next = head;
		return head;
	}
	if (ind == 0) {
		node->next = head->next;
		head->next = node;
		return head;
	}
	Node *p = head->next;
	int count = 0;
	while (p != head && count < ind - 1) {
		p = p->next;
		count++;
	}
	if (count == ind - 1) {
		node->next = p->next;
		p->next = node;
	}
	if (node == head->next) {
		head = node;
	}
	return head;
}

void output(LinkList list) {
	Node *p = list->next;
	int i = 20;
	while (i--) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int main() {
	srand(time(0));
	LinkList list = NULL;
	#define MAX_N 20
	for (int i = 0; i < MAX_N; i++) {
		int val = rand() % 100;
		Node *p = (Node *)malloc(sizeof(Node));
		p->data = i;
		p->next = NULL;
		list = insert(list, p, i);
	}
	output(list);
	return 0;
}
