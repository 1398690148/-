/*************************************************************************
    > File Name: HZOJ266.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 14时26分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1000

char str[MAX_N + 5];
char back_str[MAX_N + 5];

typedef struct Stack {
	char *data;
	int size, top;
} Stack;

typedef struct NumStack {
	int *data;
	int size, top;
} NumStack;


void initNum(NumStack *s, int size) {
	s->data = (int *)malloc(sizeof(int) * size);
	s->size = size;
	s->top = -1;
}

void init(Stack *s, int size) {
	s->data = (char *)malloc(sizeof(char) * size);
	s->size = size;
	s->top = -1;
}


int pushNum(NumStack *s, int val) {
	if (s->top == s->size - 1) return 0;
	s->data[++s->top] = val;
	return 1;
}

int push(Stack *s, char val) {
	if (s->top == s->size - 1) return 0;
	s->data[++s->top] = val;
	return 1;
}

char front(Stack *s) {
	return s->data[s->top];
}

int frontNum(NumStack *s) {
	return s->data[s->top];
}

void pop(Stack *s) {
	if (s->top == -1) return ;
	--s->top;
}

void popNum(NumStack *s) {
	if (s->top == -1) return ;
	--s->top;
}

int empty(Stack *s) {
	return s->top == -1;
}

void clear(Stack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
}

void clearNum(NumStack *s) {
	if (s == NULL) return ;
	free(s->data);
	free(s);
}

int compare(char a, char b) {
	if ((a == '+' || a == '-') && (b == '*' || b == '/' || b == '^')) return 0;
	if ((a == '*' || a == '/') && b == '^') return 0;
	if (a == '(') return 0;
	return 1;
}

int power(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}

int cal(int a, int b, char c) {
	switch (c) {
		case '+': return a + b;
		case '-': return b - a;
		case '*': return a * b;
		case '/': return b / a;
		case '^': return power(b, a);
	}
}

int main() {
	int ind = 0;
	Stack *operat = (Stack *)malloc(sizeof(Stack));
	NumStack *number = (NumStack *)malloc(sizeof(NumStack));
	init(operat, 1000);
	initNum(number, 1000);
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			printf("%c", str[i]);
			back_str[ind++] = str[i];
		} else {
			if (str[i] == '(') {
				push(operat, str[i]);
			} else if (str[i] == ')'){
				while (front(operat) != '(') {
					printf("%c", front(operat));
					back_str[ind++] = front(operat);
					pop(operat);
				}
				pop(operat);
			} else {
				while (!empty(operat) && compare(front(operat), str[i])) {
					printf("%c", front(operat));
					back_str[ind++] = front(operat);
					pop(operat);
				}
				push(operat, str[i]);
			}
		}
	}
	while (!empty(operat)) {
		printf("%c", front(operat));
		back_str[ind++] = front(operat);
		pop(operat);
	}
	printf("\n");
	clear(operat);
	for (int i = 0; i < ind; i++) {
		if (back_str[i] >= '0' && back_str[i] <= '9') {
			pushNum(number, back_str[i] - '0');
		} else {
			int a = frontNum(number);
			popNum(number);
			int b = frontNum(number);
			popNum(number);
			int c = cal(a, b, back_str[i]);
			pushNum(number, c);
		}
	}
	printf("%d", frontNum(number));
	return 0;
}
