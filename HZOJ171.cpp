/*************************************************************************
	> File Name: HZOJ171.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月05日 星期二 16时15分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

string num, num1, num2, num3;
int isCircle(string num) {
    for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
        if (num[i] != num[j]) return 0;
    }
    return 1;
}

int c2(string num) {
    if (num[0] != '1') return 0;
    for (int i = 1; i < num.size(); i++) {
        if (num[i] != '0') return 0;
    }
    return 1;
}

void make2() {
    for (int i = 0, j = num2.size() - 1; i < j; i++, j--) {
        num2[j] = num2[i];
    }
}

void make1() {
    int mid = (num1.size() + 1) / 2 - 1;
    num1[mid] -= 1;
    for (int i = mid; i >= 0; i--) {
        if (num1[i] < '0') {
            num1[i - 1] -= 1;
            num1[i] += 10;
        }
    }
    for (int i = 0, j = num1.size() - 1; i < j; i++, j--) {
        num1[j] = num1[i];
    }
}

void make3() {
    int mid = (num3.size() + 1) / 2 - 1;
    num3[mid] += 1;
    for (int i = mid; i >= 0; i--) {
        if (num3[i] > '9') {
            num3[i - 1] += 1;
            num3[i] -= 10;
        }
    }
    for (int i = 0, j = num3.size() - 1; i < j; i++, j--) {
        num3[j] = num3[i];
    }
}

int main() {
    cin >> num;
    if (isCircle(num)) {
        cout << num << endl;
        return 0;
    } 
    if (c2(num)) {
        for (int i = 1; i < num.size(); i++) {
            cout << 9;
        }
        cout << endl;
        return 0;
    }
    num1 = num2 = num3 = num;
    make2();
    int flag = 0;
    if (num2 < num) {
        make3();
        flag = 1;
    } else {
        make1();
    }
    if (flag == 1) {
        string min_num, max_num;
        min_num = max_num = num;
        for (int i = 0; i < num.size(); i++) {
            min_num[i] = max_num[i] = '0';
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            min_num[i] = num[i] - num2[i] + '0';
            max_num[i] = num3[i] - num[i] + '0';
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            if (min_num[i] < '0') {
                min_num[i - 1] -= 1;
                min_num[i] += 10;
            }
            if (max_num[i] < '0') {
                max_num[i - 1] -= 1;
                max_num[i] += 10;
            }
        }
        if (max_num < min_num) {
            cout << num3 << endl;
        } else {
            cout << num2 << endl;
        }
    } else {
        string min_num, max_num;
        min_num = max_num = num;
        for (int i = 0; i < num.size(); i++) {
            min_num[i] = max_num[i] = '0';
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            min_num[i] = num[i] - num1[i] + '0';
            max_num[i] = num2[i] - num[i] + '0';
        }
        for (int i = num.size() - 1; i >= 0; i--) {
            if (min_num[i] < '0') {
                min_num[i - 1] -= 1;
                min_num[i] += 10;
            }
            if (max_num[i] < '0') {
                max_num[i - 1] -= 1;
                max_num[i] += 10;
            }
        }
        if (max_num < min_num) {
            cout << num2 << endl;
        } else {
            cout << num1 << endl;
        } 
    }
    return 0;
}
