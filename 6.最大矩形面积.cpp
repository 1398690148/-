/*************************************************************************
    > File Name: 6.最大矩形面积.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 18时00分02秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 100000

long long arr[MAX_N + 5];
long long l[MAX_N + 5], r[MAX_N + 5];
long long s[MAX_N + 5], top;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	arr[0] = arr[n + 1] = -1;
	top = -1;
	s[++top] = 0;
	for (int i = 1; i <= n; i++) {
		while (arr[i] <= arr[s[top]]) top--;
		l[i] = s[top];
		s[++top] = i;
	}
	top = -1;
	s[++top] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (arr[i] <= arr[s[top]]) top--;
		r[i] = s[top];
		s[++top] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = ans > ((r[i] - l[i] - 1) * arr[i]) ? ans : ((r[i] - l[i] - 1) * arr[i]);
	}
	printf("%lld", ans);
	return 0;
}
