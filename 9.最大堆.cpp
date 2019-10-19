/*************************************************************************
	> File Name: 9.最大堆.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月19日 星期六 20时00分59秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) _temp = a; \
    a = b; b = _temp; \
}

void downUpdate(int *arr, int n, int ind) {
    while ((ind * 2) <= n) {
        int temp = ind, l = ind * 2, r = (ind << 1) + 1;
        if (arr[temp] < arr[l]) temp = l;
        if (r <= n && arr[temp] < arr[r]) temp = r;
        if (temp == ind) break;
        swap(arr[ind], arr[temp]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}


int main() {
    srand(time(0));
    #define MAX_N 20
    int *arr = (int *)malloc(sizeof(int) * MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < MAX_N; i++) {
        i == 0 || printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    heap_sort(arr, MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        i == 0 || printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
