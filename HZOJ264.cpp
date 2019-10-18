/*************************************************************************
    > File Name: HZOJ264.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月17日 星期四 17时55分05秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 100000

long long arr[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];
long long s[MAX_N + 5], top;


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	arr[0] = arr[n + 1] = -1;
	top = -1;
	s[++top] = 0;
	for (int i = 1; i <= n; i++) {
		while (arr[s[top]] >= arr[i]) top--;
		l[i] = s[top];
		s[++top] = i;
	}
	top = -1;
	s[++top] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (arr[s[top]] >= arr[i]) top--;
		r[i] = s[top];
		s[++top] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, ((r[i] - l[i] - 1) * arr[i]));
	}
	cout << ans << endl;
	return 0;
}
