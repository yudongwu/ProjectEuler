#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool issquare(int n)			//判断一个自然数是否为一个平方数
{
	if (ceil(sqrt(n)) * ceil(sqrt(n)) == n)
		return true;
	else
		return false;
}

bool isprim(int n)				//素数判断
{
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool judge(long long n)
{
	int i = 1;
	long long t;
	while ((t = (n - 2 * (i * i))) > 0) {
		if (isprim(t))
			return true;
		i++;
	}
	return false;
}

int main()
{
	for (long long i = 1001; i < 100000000; i = i + 2) {
		if (!isprim(i) && !judge(i)) {
			printf("%lld\n", i);
			break;
		}
	}
	return 0;
}

//Answer:5777
