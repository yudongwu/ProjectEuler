#include<stdio.h>

int FactorSum(int n)			//计算n的所有小于n的因素和
{
	int i;
	int sum = 1;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	return sum;
}

int main()
{
	int t, i = 2;
	int sum = 0;
	while (i < 10000) {
		t = FactorSum(i);
		if (t != i && FactorSum(t) == i)
			sum += i;
		i++;
	}
	printf("%d\n", sum);
	return 0;
}

//Answer:31626
