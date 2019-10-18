/*************************************************************************
    > File Name: HZOJ262.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 14时17分03秒
 ************************************************************************/

#include <stdio.h>

int sum(int r, int k) {
	if (k == 1 || k == r) {
		return 1;
	}
	return sum(1, k - 1) + sum(k + 1, r);
}

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += sum(n, i);
	}
	printf("%d", ans);
	return 0;
}
