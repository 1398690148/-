/*************************************************************************
	> File Name: HZOJ242.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月03日 星期日 18时53分47秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

long long arr[MAX_N + 5], b[MAX_N + 5];

bool check(long long *arr, long long n, long long m, long long val) {
    long long num = 0;
    for (int i = 1; i <= n; i++) b[i] = arr[i] - val;
    for (long long i = 1; i <= n; i++) b[i] += b[i - 1];
    for (long long i = m; i <= n; i++) {
        num = min(num, b[i - m]);
        if (b[i] - num >= 0) return true;
    }
    return false;
}

long long binary_search(long long *arr, long long l, long long r, long long n, long long m) {
    if (l == r) return l;
    long long mid = (l + r + 1) >> 1;
    if (check(arr, n, m, mid)) return binary_search(arr, mid, r, n, m);
    else return binary_search(arr, l, mid - 1, n, m);
}

int main() {
    long long n, m, min_num, max_num;
     cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
        if (i == 1) min_num = max_num = arr[i];
        min_num = min(min_num, arr[i]);
        max_num = max(max_num, arr[i]);
    }
    cout << binary_search(arr, min_num, max_num, n, m) << endl;
    return 0;
}
