#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool isprim(int n)
{
	int i = 2;
	for (; i * i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool circular_prime(int n)
{
	int i, j, flag = 1;
	char s[6];
	int sum = 0;
	sprintf(s, "%d", n);
	int len = strlen(s);
	for (i = 0; i < len; i++) {
		if (s[i] != '1' && s[i] != '3' && s[i] != '7' && s[i] != '9')
			return false;
	}
	for (i = 0; i < len; i++) {
		for (j = i; j < i + len - 1; j++) {
			sum += s[j % len] - '0';
			sum *= 10;
		}
		sum += s[j % len] - '0';
		if (!isprim(sum))
			return false;
		sum = 0;
	}
	return true;
}

int main()
{
	int sum = 4;				//ÒÑ°üº¬2,3,5,7
	for (int i = 11; i < 1000000; i++) {
		if (circular_prime(i))
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}

//Answer:55
