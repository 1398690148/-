/*************************************************************************
	> File Name: 17.大整数乘法.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月16日 星期六 16时44分08秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000

string num1;
string num2;
int a[MAX_N + 5] = {0}, b[MAX_N + 5] = {0}, c[MAX_N + 5] = {0};

int main() {
    cin >> num1 >> num2;
    int len1 = num1.length();
    int len2 = num2.length();
    for (int i = 0; i < len1; i++) {
        a[i] = num1[len1 - i - 1] - '0';
    }
    for (int i = 0; i < len2; i++) b[i] = num2[len2 - i - 1] - '0';
    int k = len1 + len2;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            c[i + j] += a[i] * b[j];
        }
    }
    while (c[k] == 0) k--;
    for (int j = 0; j <= k; j++) {
        if (c[j] < 10) continue;
        c[j + 1] += c[j] / 10;
        c[j] %= 10;
        j == k && k++;
    }
    for (int i = k; i >= 0; i--) {
        cout << c[i];
    }
    return 0;
}
