/*************************************************************************
	> File Name: HZOJ284.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月02日 星期六 15时20分20秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define MAX_N 10000

struct Data {
    int d, p, id;
    bool operator<(const Data &a) const {
        if (p - a.p) return p < a.p;
        if (d - a.d) return d < a.d;
        return id < a.id;
    }
} arr[MAX_N + 5];

set<Data> s;

bool cmp(const Data &a, const Data &b) {
    if (a.d - b.d) return a.d < b.d;
    if (a.p - b.p) return a.p < b.p;
    return a.id < b.id;
}

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].p >> arr[i].d, arr[i].id = i;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        if (arr[i].d > s.size()) {
            s.insert(arr[i]);
        
        } else if(s.begin()->p < arr[i].p) {
            s.erase(s.begin());
            s.insert(arr[i]);
        }
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        ans += iter->p;
    }
    cout << ans << endl;

    return 0;
}
