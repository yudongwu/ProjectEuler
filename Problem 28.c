#include<stdio.h>
void countSum()
{
	int i = 3;
	int sum = 1;
	int n = (1001 + 1) / 2 - 1;
	while (n--) {
		int t = i * i;
		sum += (4 * t - (i - 1) * 6);
		i = i + 2;
	}
	printf("%d\n", sum);
}

int main()
{
	countSum();
	return 0;
}

//Answer:669171001
