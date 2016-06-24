#include<stdio.h>
#include<stdbool.h>

bool test(int *a, int n)
{
	bool flag = true;
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1]) {
			flag = false;
			break;
		}
	}
	return flag;
}

bool palindromes(int n, int base)	//判断整数n在基为base时是否为回文数
{
	int a[100];
	int i = 0;
	while (n) {
		a[i++] = n % base;
		n /= base;
	}
	return test(a, i);
}

int main(void)
{
	int sum = 0;
	for (int i = 1; i <= 1000000; i += 2) {
		if (palindromes(i, 10) && palindromes(i, 2))
			sum += i;
	}
	printf("%d\n", sum);
	return 0;
}

//Answer:872187
