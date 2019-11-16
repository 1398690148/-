/*************************************************************************
	> File Name: HZOJ381.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月09日 星期六 15时19分02秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Data {
    char name[20];
    int lastgrade;
    int classgrade;
    char isclass[2];
    char isWest[2];
    int cnt;
    int flag;
    int sum;
} Data;

Data data[100];

int cmp(Data a, Data b) {
    if (a.sum == b.sum) return a.flag < b.flag;
    return a.sum > b.sum;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data[i].name >> data[i].lastgrade >> data[i].classgrade;
        cin >> data[i].isclass >> data[i].isWest >> data[i].cnt;
        data[i].flag = i;
        if (data[i].lastgrade > 80 && data[i].cnt >= 1) {
            data[i].sum += 8000;
        }
        if (data[i].lastgrade > 85 && data[i].classgrade > 80) {
            data[i].sum += 4000;
        }
        if (data[i].lastgrade > 90) {
            data[i].sum += 2000;
        }
        if (data[i].lastgrade > 85 && data[i].isWest[0] == 'Y') {
            data[i].sum += 1000;
        }
        if (data[i].classgrade > 80 && data[i].isclass[0] == 'Y') {
            data[i].sum += 850;
        }
        ans += data[i].sum;
    }
    sort(data, data + n, cmp);
    cout << data[0].name << endl;
    cout << data[0].sum << endl;
    cout << ans << endl;
    
    return 0;
}

