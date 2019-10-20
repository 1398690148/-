/*************************************************************************
	> File Name: 10.sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月20日 星期日 18时37分22秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) { \
    __typeof(a) _temp = a; \
    a = b; b = _temp; \
}

#define TEST(arr, n, func, args...) { \
    int *num = (int *)malloc(sizeof(int) * n); \
    memcpy(num, arr, sizeof(int) * n); \
    output(num, n); \
    printf("%s = ", #func); \
    func(args); \
    output(num, n); \
    free(num); \
}

void select_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) {
        int ind = i;
        for (int j = i + 1; j < n; j++) {
            if (num[ind] > num[j]) {
                ind = j;
            }
        }
        if (ind != i) {
            swap(num[i], num[ind]);
        }
    }
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (l > r) {
        return ;
    }
    int low = l, high = r, z = num[l];
    while (low < high) {
        while (low < high && z <= num[high]) high--;
        if (low < high) num[low] = num[high];
        while (low < high && z >= num[low]) low++;
        if (low < high) num[high] = num[low];
    }
    num[low] = z;
    quick_sort(num, l, low - 1);
    quick_sort(num, low + 1, r);
    return ;
}

void randint(int *arr, int n) {
    while (n--) {
        arr[n] = rand() % 100;
    }
    return ;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define MAX_N 20
    int arr[MAX_N];
    randint(arr, MAX_N);
    TEST(arr, MAX_N, select_sort, num, MAX_N);
    TEST(arr, MAX_N, quick_sort, num, 0, MAX_N);
    return 0;
}
