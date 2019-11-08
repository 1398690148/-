/*************************************************************************
	> File Name: HZOJ572.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年11月02日 星期六 14时32分35秒
 ************************************************************************/

#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
#define MAX_N 400000

long long a[MAX_N + 5], b[MAX_N + 5];

struct Data {
    Data(int val, int i, int j) : val(val), i(i), j(j) {

    } 
    long long val, i, j;
    bool operator<(const Data &a) const {
        if (val - a.val) return val < a.val;
        if (i - a.i) return i < a.i;
        return j < a.j;
    }
};

set<Data> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    s.insert(Data(a[0] + b[0], 0, 0));
    for (int i = 0; i < n; i++) {
        int val = s.begin()->val;
        int x = s.begin()->i;
        int y = s.begin()->j;
        s.erase(s.begin());
        printf("%lld\n", val);
        if (x + 1 < n) s.insert(Data(a[x + 1] + b[y], x + 1, y));
        if (y + 1 < n) s.insert(Data(a[x] + b[y + 1], x, y + 1));
    }
    return 0;
}
