/*************************************************************************
    > File Name: 2.binaryTree.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月17日 星期四 19时23分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
	Node *root;
	int n;
} Tree;

Node *getNewNode(int val) {
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->lchild = p->rchild = NULL;
	return p;
}

Tree *getNewTree() {
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->root = NULL;
	tree->n = 0;
	return tree;
}

Node *insertNode(Node *root, int val, int *flag) {
	if (root == NULL) {
		*flag = 1;
		return getNewNode(val);
	}
	if (root->data == val) return root;
	if (root->data > val) root->lchild = insertNode(root->lchild, val, flag);
	else root->rchild = insertNode(root->rchild, val, flag);
	return root;
}

void insert(Tree *tree, int val) {
	int flag = 0;
	tree->root = insertNode(tree->root, val, &flag);
	tree->n += flag;
	return ;
}

void in_orderNode(Node *node) {
	if (node == NULL) return ;
	if (node->lchild != NULL) in_orderNode(node->lchild);
	printf("%d ", node->data);
	if (node->rchild != NULL) in_orderNode(node->rchild);
	return ;
}

void in_order(Tree *tree) {
	printf("in_order(%d) = ", tree->n);
	in_orderNode(tree->root);
	printf("\n");
	return ;
}

void pre_orderNode(Node *node) {
	if (node == NULL) return ;
	printf("%d ", node->data);
	if (node->lchild != NULL) pre_orderNode(node->lchild);
	if (node->rchild != NULL) pre_orderNode(node->rchild);
	return ;
}

void pre_order(Tree *tree) {
	printf("pre_order(%d) = ", tree->n);
	pre_orderNode(tree->root);
	printf("\n");
	return ;
}

void post_orderNode(Node *node) {
	if (node == NULL) return ;
	if (node->lchild != NULL) post_orderNode(node->lchild);
	if (node->rchild != NULL) post_orderNode(node->rchild);
	printf("%d ", node->data);
	return ;
}

void post_order(Tree *tree) {
	printf("post_order(%d) = ", tree->n);
	post_orderNode(tree->root);
	printf("\n");
	return ;
}
void clearNode(Node *node) {
	if (node == NULL) return ;
	clearNode(node->lchild);
	clearNode(node->rchild);
	free(node);
	return ;
}

void clearTree(Tree *tree) {
	if (tree == NULL) return ;
	clearNode(tree->root);
	free(tree);
	return ;
}

void outputNode(Node *root) {
	if (root == NULL) return ;
	printf("%d", root->data);
	printf("(");
	if (root->lchild != NULL) outputNode(root->lchild);
	printf(",");
	if (root->rchild != NULL) outputNode(root->rchild);
	printf(")");
	return ;
}

void output(Tree *tree) {
	if (tree == NULL) return ;
	printf("tree(%d) = ", tree->n);
	outputNode(tree->root);
	printf("\n");
	return ;
}

int main() {
	srand(time(0));
	Tree *tree = getNewTree();
	#define MAX_N 5
	for (int i = 0; i < MAX_N; i++) {
		int val = rand() % 100;
		insert(tree, val);
	}
	output(tree);
	pre_order(tree);
	in_order(tree);
	post_order(tree);
	clearTree(tree);
	return 0;
}
