#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool palindromic(int n)			//判断一个整数是否为回文数
{
	char s[10];
	sprintf(s, "%d", n);		//将整数n保存在字符数组s中
	int i, len;
	len = strlen(s);
	for (i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

bool have_the_factor(int n)		//判断是否含有两个3位数的因数
{
	int s = 999;
	int r, b;
	while (s > 100) {
		if ((n % s) == 0 && ((n / s) > 100 && (n / s) < 1000))
			return true;
		s--;
	}
	return false;
}

int main()
{
	int i = 1000000;
	while (i > 0) {
		if (palindromic(i) && have_the_factor(i)) {
			printf("%d\n", i);
			break;
		}
		i--;
	}
	return 0;
}

//Answer:906609

