/*************************************************************************
	> File Name: 16.哈希代码演示.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 14时50分20秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node, *LinkedList;

typedef struct HashTable {
    LinkedList *data;
    int size;
} HashTable;

Node *init_node(char *str, LinkedList head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (LinkedList *)calloc(sizeof(LinkedList), h->size);
    return h;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    free(q);
    return ;
}

int BKDRHash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) {
        hash  = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}

int insert(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) {
        p = p->next;
    }
    return p != NULL;
}

void clear(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
       clear_node(h->data[i]); 
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    #define MAX_N 100
    HashTable *h = init(MAX_N + 5);
    char str[MAX_N + 5];
    while (~scanf("%d%s", &op, str)) {
        switch (op) {
            case 0: {
                printf("Insert %s to HashTable\n", str);
                insert(h, str);
            } break;
            case 1: {
                printf("Search %s result = %d\n", str, search(h, str));
            }
        }
    }
    clear(h);
    return 0;
}
