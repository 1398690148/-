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

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (num[j] < num[j - 1]) {
                swap(num[j], num[j - 1]);
            }
        }
    }
}

void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j + 1], num[j]);
                times++;
            }
        }
    }
    return ;
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int low = l, high = mid + 1, loc = 0;
    while (low <= mid || high <= r) {
        if (high > r || (low <= mid && num[low] <= num[high])) {
            temp[loc++] = num[low++];
        } else {
            temp[loc++] = num[high++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
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
    for (int i = 0; i <= n; i++) {
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
    TEST(arr, MAX_N, insert_sort, num, MAX_N);
    TEST(arr, MAX_N, bubble_sort, num, MAX_N);
    TEST(arr, MAX_N, merge_sort, num, 0, MAX_N);
    return 0;
}
