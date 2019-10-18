/*************************************************************************
    > File Name: 4.建立顺序存储完全二叉树.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 16时37分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	char data;
	struct Node *lchild, *rchild;
} Node, *pNode;

pNode init(char val) {
	pNode node = (pNode)malloc(sizeof(Node));
	node->data = val;
	node->lchild = node->rchild = NULL;
	return node;
}

void clear(pNode node) {
	if (node == NULL) return ;
	if (node->lchild == NULL) clear(node->lchild);
	if (node->rchild == NULL) clear(node->rchild);
	free(node);
}

void output(pNode p) {
    if (!p) return ;
    printf("%c", p->data);
    if (p->lchild == NULL && p->rchild == NULL) {
        return ;
    }
    printf("(");
    if (p->lchild) {
        output(p->lchild);
    }
    if (p->rchild) {
        printf(",");
        output(p->rchild);
    }
    printf(")");
}

int main() {
	int len = 0, size = 50;
    char *str = (char *)malloc(sizeof(char) * size);
    char ch;
    while (scanf("%c", &ch)) {
        if (ch == '$') break;
        str[len++] = ch;
        if (len == size) {
            size *= 2;
            str = (char *)realloc(str, size);
        }
    }
    pNode *p_arr = (pNode *)malloc(sizeof(Node) * (strlen(str) / 2 + 1));
    int ind = 1;
    p_arr[ind] = NULL;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') continue;
        p_arr[ind] = init(str[i]);
        if (ind != 1) {
            if (ind % 2) {
                p_arr[ind / 2]->rchild = p_arr[ind];
            } else {
                p_arr[ind / 2]->lchild = p_arr[ind];
            }
        }
        ++ind;
    }
    output(p_arr[1]);
    printf("\n");
    clear(p_arr[1]);
    free(p_arr);
    free(str);
    return 0;
}
