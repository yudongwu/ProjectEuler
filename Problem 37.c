#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool isprim(int n)
{
	int i = 2;
	if (n == 1)
		return false;
	for (; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool truncatable_prime(int n)
{
	int i, j, t, flag = 1;
	char s[6];
	int sum = 0;
	sprintf(s, "%d", n);
	int len = strlen(s);

	if (!isprim(s[0] - '0') || !isprim(s[len - 1] - '0'))
		return false;

	for (i = 1; i < len - 1; i++) {
		t = s[i] - '0';
		if (t == 0 || t == 2 || t == 4 || t == 6 || t == 5 || t == 8)
			return false;
	}

	for (i = 1; i < len - 1; i++) {
		for (j = i; j < len - 1; j++) {
			sum += s[j] - '0';
			sum *= 10;
		}
		sum += s[j] - '0';
		if (!isprim(sum))
			return false;
		sum = 0;
	}
	j = len - 1;
	i = 0;
	while (j > i) {
		for (i = 0; i < j; i++) {
			sum += s[i] - '0';
			sum *= 10;
		}
		sum += s[i] - '0';
		if (!isprim(sum))
			return false;
		sum = 0;
		i = 0;
		j--;
	}
	return true;
}

int main()
{
	int sum, count;
	sum = count = 0;
	int i = 13;
	while (1) {
		if (isprim(i) && truncatable_prime(i)) {
			count++;
			sum += i;
			//printf("%d\n",i);
		}
		i = i + 2;
		if (count == 11)
			break;
	}
	printf("%d\n", sum);
	return 0;
}

//Answer:748317
