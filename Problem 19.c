#include <stdio.h>
#include <stdbool.h>

const int a[2][12] = { {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool leapYear(int n)			//判断闰年
{
	return (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0));
}

bool issunday(int n)			//判断某天是否是星期天
{
	return (n % 7 == 0 ? true : false);
}

void solve(void)
{
	int num, i, j, count;
	count = 0;

	i = 1901;
	num = 1;
	while (i < 2000) {

		int t = (leapYear(i) ? 1 : 0);	//判断闰年
		for (j = 0; j < 12; j++) {
			num += a[t][j];
			if (issunday(num))
				count++;
		}
		i++;
	}
	printf("%d\n", count);
}

int main(void)
{
	solve();
	return 0;
}

int main()
{
	solve();
	return 0;
}

//Answer:171
