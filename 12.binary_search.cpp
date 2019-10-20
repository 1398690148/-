/*************************************************************************
	> File Name: 12.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月20日 星期日 20时38分59秒
 ************************************************************************/
#include <stdio.h>

#define P(func, args...) { \
    printf("%s = %d\n", #func, func(args)); \
}

int binary_search(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        else if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    P(binary_search, arr, 10, 7);
    P(binary_search2, arr2, 10);
    P(binary_search3, arr3, 10);
    return 0;
}
