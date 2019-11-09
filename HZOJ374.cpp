/*************************************************************************
	> File Name: HZOJ374.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 09时14分12秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;


int num[10] = {0};

int is_val(int a) {
    while (a > 0) {
        int c = a % 10;
        if (c == 0) return 0;
        if (num[c] != 0) return 0;
        num[c] += 1;
        a = a / 10;
    }
    return 1;
}

int check(int a, int b, int c) {
    memset(num, 0, sizeof(num));
    if (!is_val(a)) return 0;
    if (!is_val(b)) return 0;
    if (!is_val(c)) return 0;
    for (int i = 1; i < 10; i++) {
        if (num[i] == 0) return 0;
    }
    return 1;
}

int main() {
    int x, y, z, flag = 1;
    cin >> x >> y >> z;
    for (int i = 1; i < 1000; i++) {
        int a = x * i;
        int b = y * i;
        int c = z * i;
        if (a < 100 || a > 999 || b < 100 || b > 999 || c < 100 || c > 999) continue;
        if (check(a, b, c)) {
            cout << a << " " << b << " " << c << endl;
            flag = 0;
        }
    }
    if (flag) {
        cout << "No" << endl;
    }
    return 0;
}
