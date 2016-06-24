#include<stdio.h>
#include<math.h>

long long combinatoric(int n, int r)	//计算组合数的函数
{
	int i;
	long long s = 1;
	if (r > n / 2)
		r = n - r;
	for (i = n; i >= n - r + 1; i--) {
		s *= i;
	}
	for (i = 1; i <= r; i++) {
		s /= i;
	}
	return s;
}

int main()
{
	int i, j, s;
	s = 0;
	for (i = 23; i <= 100; i++) {
		j = 3;
		while (combinatoric(i, j) < 1000000)
			j++;
		if (i % 2) {
			s += (i / 2 - j + 1) * 2;	//利用组合数的对称性，分奇偶两种情况
		} else {
			s += (i / 2 - j) * 2 + 1;
		}
	}
	printf("%d\n", s);
	return 0;
}

//Answer:4075
