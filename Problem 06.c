#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 100

int powplus(int n, int k)
{
	int s = 1;
	while (k--) {
		s *= n;
	}
	return s;
}

int sum1(int n)
{
	return powplus((n + 1) * n / 2, 2);
}

int sum2(int n)
{
	return (n * (n + 1) * (2 * n + 1)) / 6;
}

void solve()
{
	printf("%d\n", sum1(N));
	printf("%d\n", sum2(N));
	printf("%d\n", sum1(N) - sum2(N));
}

int main()
{
	solve();
	return 0;
}

//Answer:25164150
