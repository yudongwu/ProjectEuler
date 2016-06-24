#include<stdio.h>
#define N 12000

int gcd(int a, int b)			//求最大公约数函数
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve()
{
	int a, b, i, j, ans;
	ans = 0;
	for (i = 5; i <= N; i++) {
		a = i / 3;
		b = i / 2;
		for (j = a + 1; j < b + 1; j++) {
			if (gcd(i, j) == 1)
				ans++;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	solve();
	return 0;
}

//Answer:7295372
