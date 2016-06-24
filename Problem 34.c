#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int factorial(int n)			//阶乘函数
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

bool judge(int n)				//判断一个整数是否符合题意的函数
{
	char s[10];
	sprintf(s, "%d", n);
	int len = strlen(s);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += factorial(s[i] - '0');
	}
	if (n == sum)
		return true;
	else
		return false;
}

int main()
{
	int sum = 0;
	for (int i = 3; i < 1000000; i++) {
		if (judge(i))
			sum += i;
	}
	printf("%d\n", sum);
	return 0;
}

//Answer:40730
