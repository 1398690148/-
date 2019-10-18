/*************************************************************************
    > File Name: 5.GetMin.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 17时19分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int *data;
	int size, top;
} Stack;

Stack *init(int size) {
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = (int *)malloc(sizeof(int) * size);
	s->size = size;
	s->top = -1;
	return s;
}

int push(Stack *s, int val) {
	if (!s) return 0;
	if (s->top == s->size - 1) return 0;
	s->data[++s->top] = val;
	return 1;
}

int front(Stack *s) {
	return s->data[s->top];
}

int empty(Stack *s) {
	return s->top == -1;
}

void pop(Stack *s) {
	if (!s) return ;
	if (s->top == -1) return ;
	--s->top;
	return ;
}

void clear(Stack *s) {
	if (!s) return ;
	free(s);
}

int main() {
	int size = 50;
	Stack *s = init(size);
	Stack *n = init(size);
	int op = 0, num;
	while (scanf("%d", &op)) {
		switch (op) {
			case 0:
				scanf("%d", &num);
				push(s, num);
				if (empty(n)) {
					push(n, num);
					break;
				}
				if (!empty(n) && num < front(n)) {
					push(n, num);
				} else if (!empty(n) && num >= front(n)){
					push(n, front(n));
				}
				break;
			case 1:
				pop(s);
				pop(n);
				break;
			case 2:
				printf("%d", front(n));
				break;
		}
	}
	return 0;
}
