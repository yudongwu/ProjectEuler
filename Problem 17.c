#include <stdio.h>
#include <stdbool.h>

int a[101] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };

void init(void)					//初始化数组
{
	a[20] = 6;
	a[30] = 6;
	a[40] = 5;
	a[50] = 5;
	a[60] = 5;
	a[70] = 7;
	a[80] = 6;
	a[90] = 6;
	a[100] = 7;
}

int within100(void)				//计算1~99所含字母的和
{
	int i, sum, t;
	t = sum = 0;
	for (i = 1; i <= 9; i++)
		t += a[i];
	for (i = 1; i <= 19; i++)
		sum += a[i];
	for (i = 2; i <= 9; i++) {
		sum += a[i * 10] * 10;
		sum += t;
	}
	return sum;
}

void solve(void)
{
	int i;
	int sum, t;
	sum = t = within100();
	for (i = 1; i < 10; i++) {
		sum += (a[i] + 10) * 99 + (a[i] + 7) + t;
	}
	sum += 11;

	printf("%d\n", sum);
}

int main(void)
{
	init();
	solve();
	return 0;
}
//Answer:21124
