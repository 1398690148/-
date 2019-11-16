/*************************************************************************
	> File Name: HZOJ377.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 10时15分28秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 300

char str[MAX_N + 5];

int main() {
    int num = 0, flag = 1;
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') num++;
        if (str[i] == ')') num--;
        if (num < 0) {
            cout << "NO" << endl;
            flag = 0;
            break;
        }
    }
    if (flag) {
        if (num != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}
