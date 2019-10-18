/*************************************************************************
    > File Name: 3.快速幂.cpp
    > Author: 
    > Mail: 
    > Created Time: 2019年10月18日 星期五 16时32分34秒
 ************************************************************************/

#include <stdio.h>

int pow(int a, int b, int p) {
	int ans = 1 % p;
	while (b) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int main() {
	int a, b, p;
	scanf("%d%d%d", &a, &b, &p);
	printf("%d ^ %d %% %d = %d\n", a, b, p, pow(a, b, p));
}
