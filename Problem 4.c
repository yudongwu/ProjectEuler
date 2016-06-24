#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool palindromic(int n)			//�ж�һ�������Ƿ�Ϊ������
{
	char s[10];
	sprintf(s, "%d", n);		//������n�������ַ�����s��
	int i, len;
	len = strlen(s);
	for (i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

bool have_the_factor(int n)		//�ж��Ƿ�������3λ��������
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

