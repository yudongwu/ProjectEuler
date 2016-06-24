#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int powcount(long long n)		//计算2的幂数
{
	int count = 0;
	while (n >>= 1)
		count++;
	return count;
}

bool ispower(long long v)		//判断n是否为2的幂
{
	if (((v & (v - 1)) == 0))
		return true;
	else
		return false;
}

int length(long long n)
{
	int sum = 1;
	while (1) {
		if (n == 1)
			break;
		if ((n & 1) == 0) {
			if (ispower(n))
				return sum + powcount(n);
			else
				n = n / 2;
		} else
			n = 3 * n + 1;
		sum++;
	}
	return sum;
}

int main()
{
	int i, t, k, max = 0;
	for (i = 2; i < 1000000; i++) {
		t = length(i);
		if (t > max) {
			max = t;
			k = i;
		}
	}
	printf("%lld\n", k);
	return 0;
}

//Answer:837799
