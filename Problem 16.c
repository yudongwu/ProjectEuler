#include <stdio.h>
#include <stdbool.h>

void solve(void)
{
	int a[100000] = { 0 };
	int n, sum, i, j;
	n = sum = 0;
	a[0] = 1;
	for (i = 0; i < 1000; i++) {	//以1000进制的方法存储
		for (j = 0; j <= n; j++) {
			a[j] *= 2;
		}
		for (j = 0; j <= n; j++) {
			if (a[j] >= 10000) {
				a[j] %= 10000;
				a[j + 1] ++;
				n++;
			}
		}
	}
	for (i = 0; i <= n; i++) {
		sum += a[i] / 10000;
		a[i] %= 10000;
		sum += a[i] / 1000;
		a[i] %= 1000;
		sum += a[i] / 100;
		a[i] %= 100;
		sum += a[i] / 10;
		a[i] %= 10;
		sum += a[i];

	}
	printf("%d\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

//Answer:1366
