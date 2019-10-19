/*************************************************************************
	> File Name: 7.线索化二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月19日 星期六 14时37分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORMAL 0
#define THREAD 1

typedef struct Node {
    int data;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = NORMAL;
    return p;
}

Node *insert(Node *node, int val) {
    if (node == NULL) return getNewNode(val);
    if (node->data == val) return node;
    if (node->data > val) node->lchild = insert(node->lchild, val);
    else node->rchild = insert(node->rchild, val);
    return node;
}

void build_thread(Node *p) {
    if (p == NULL) return ;
    static Node *pre = NULL;
    build_thread(p->lchild);
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = THREAD;
    }
    pre = p;
    build_thread(p->rchild);
    return ;
}

void in_order(Node *p) {
    if (p == NULL) return ;
    if (p->ltag == NORMAL && p->lchild) in_order(p->lchild);
    printf("%d ", p->data);
    if (p->rtag == NORMAL && p->rchild) in_order(p->rchild);
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    if (node->ltag == NORMAL && node->lchild) clear(node->lchild);
    if (node->rtag == NORMAL && node->rchild) clear(node->rchild);
    free(node);
}

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *node) {
    if (node == NULL) return ;
    Node *p = most_left(node);
    while (p) {
        printf("%d ", p->data);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = most_left(p->rchild);
        }
    }
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    output(root);
    printf("\n");
    in_order(root);
    printf("\n");
    clear(root);
    return 0;
}
