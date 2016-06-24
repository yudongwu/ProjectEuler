//��Problem 46��Goldbach's other conjecture
// Completed on Fri, 26 Jul 2013, 16:58
// Language: C11
//
// ��Ȩ���У�C��acutus   (mail: acutus@126.com) 
// ���͵�ַ��http://www.cnblogs.com/acutus/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool issquare(int n)			//�ж�һ����Ȼ���Ƿ�Ϊһ��ƽ����
{
	if (ceil(sqrt(n)) * ceil(sqrt(n)) == n)
		return true;
	else
		return false;
}

bool isprim(int n)				//�����ж�
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
