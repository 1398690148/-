/*************************************************************************
	> File Name: 8.堆.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月19日 星期六 18时08分44秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->size = n;
    q->cnt = 0;
    return q;
}

int top(priority_queue *q) {
    return q->data[1];
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return ;
}

int push(priority_queue *q, int val) {
    if (q->cnt == q->size) return 0;
    q->data[++q->cnt] = val;
    int ind = q->cnt;
    while ((ind >> 1) > 0 && q->data[ind] > q->data[ind >> 1]) {
        swap(q->data[ind], q->data[ind >> 1]);
        ind >>= 1;
    }
    return 1;
}

int empty(priority_queue *q) {
    return q->cnt == 0;
}

int pop(priority_queue *q) {
    if (empty(q)) return 0;
    swap(q->data[1], q->data[q->cnt]);
    q->cnt--;
    int ind = 1;
    while ((ind * 2) <= q->cnt) {
        int temp = ind, l = ind * 2, r = (ind * 2 + 1);
        if (q->data[l] > q->data[temp]) temp = l;
        if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));    
    #define MAX_N 20
    priority_queue *q = init(MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        int val = rand() % 100;
        push(q, val);
    }
    for (int i = 0; i < MAX_N; i++) {
        i == 0 || printf(" ");
        printf("%d", top(q));
        pop(q);
    }
    printf("\n");
    for (int i = 1; i <= MAX_N; i++) {
        i == 1 || printf(" ");
        printf("%d", q->data[i]);
    }
    printf("\n");
    clear(q);
    return 0;
}
