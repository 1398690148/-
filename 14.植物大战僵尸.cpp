/*************************************************************************
	> File Name: 14.植物大战僵尸.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月24日 星期四 16时41分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num, f, s;
} Node;

typedef struct Heap {
    Node *data;
    int cnt, size;
} Heap;

#define swap(a, b) { \
	__typeof(a) __temp; \
	__temp = (a); \
	(a) = (b); \
	(b) = __temp; \
}

int cmp_node(Node a, Node b) {
    if (a.f > b.f) return 1;
    if (a.f == b.f && a.num < b.num) return 1;
    return 0;
}

void init(Heap *h, int size) {
    h->data = (Node *)malloc(sizeof(Node) * size);
    h->cnt = 0;
    h->size = size;
}

int push(Heap *h, Node val) {
    if (h->cnt == h->size) return 0;
    h->data[h->cnt].f = val.f;
    h->data[h->cnt].s = val.s;
    h->data[h->cnt].num = val.num;
    int current = h->cnt;
    int father = (current - 1) / 2;
    while (cmp_node(h->data[current], h->data[father])) {
        swap(h->data[current], h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->cnt++;
    return 1;
}

void update_heap(Heap *h, int i, int n) {
    int temp = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && cmp_node(h->data[l], h->data[temp])) temp = l;
    if (r < n && cmp_node(h->data[r], h->data[temp])) temp = r;
    if (temp != i) {
        swap(h->data[i], h->data[temp]);
        update_heap(h, temp, n);
    }
}

Node top(Heap *h) {
    return h->data[0];
}

void pop(Heap *h) {
    if (h->cnt == 0) return ;
    h->cnt--;
    swap(h->data[0], h->data[h->cnt]);
    update_heap(h, 0, h->cnt);
}

void sum(Heap *h) {
    for (int i = 0; i < h->cnt; i++) {
        h->data[i].f += h->data[i].s;
    }
    for (int i = h->cnt / 2; i >= 0; i--) {
        update_heap(h, i, h->cnt);
    }
    return ;
}

void clear(Heap *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h);
}

int main() {
    int t, n; 
    scanf("%d", &t);
    Heap *h = (Heap *)malloc(sizeof(Heap));
    init(h, 50000);
    for (int j = 0; j < t; j++) {
        Node m;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
        	scanf("%d%d", &m.f, &m.s);
            m.num = i + 1;
        	push(h, m);
    	}
        printf("Case #%d:\n", j + 1);
        for (int i = 0; i < n; i++) {
     	   	i && printf(" ");
            printf("%d", top(h).num);
            pop(h);
            sum(h);
            printf("\n h(%d) = ", h->cnt);
            for (int k = 0; k < h->cnt; k++) {
                printf("%d ", h->data[k].num);
            }
            printf("\n");   
    	}
    }
    clear(h);
    return 0;
}
