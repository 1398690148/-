/*************************************************************************
	> File Name: HZOJ378.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 15时07分07秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;
#define MAX_N 300

char str[MAX_N + 5];
stack<char> s;

int main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        switch (str[i]) {
            case '(' : {
                s.push(str[i]);
            } break;
            case ')' : {
                if (s.top() != '(') {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
            } break;
            case '[' : {
                s.push(str[i]);
            } break;
            case ']' : {
                if (s.top() != '[') {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
            } break;
            case '{' : {
                s.push(str[i]);
            } break;
            case '}' : {
                if (s.top() != '{') {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
            } break;
            default : {
                
            } break;
        }
    }
    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
