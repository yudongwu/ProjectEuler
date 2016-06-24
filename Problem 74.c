#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define N 1000000
long long fac[10];				//保存1~ 9阶乘的数组

long long factorial(int n)		//计算阶乘函数
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

void init()						//初始化数组
{
	int i;
	for (i = 0; i <= 9; i++) {
		fac[i] = factorial(i);
	}
}

long long sum(long long n)		//计算整数n各位的阶乘的和
{
	int ans = 0;
	while (n) {
		ans += fac[n % 10];
		n /= 10;
	}
	return ans;
}

bool fun(int n)
{
	int i, count, t;
	bool flag = false;
	count = 0;
	while (1) {
		switch (n) {
		case 1:
			count += 1;
			flag = true;
			break;
		case 2:
			count += 1;
			flag = true;
			break;
		case 169:
			count += 3;
			flag = true;
			break;
		case 1454:
			count += 3;
			flag = true;
			break;
		case 871:
			count += 2;
			flag = true;
			break;
		case 872:
			count += 2;
			flag = true;
			break;
		case 145:
			count += 1;
			flag = true;
			break;
		default:
			t = sum(n);
			if (n == t) {
				flag = true;
				break;
			} else {
				n = t;
				count++;
				break;
			}
		}
		if (flag)
			break;
	}
	if (count == 60)
		return true;
	else
		return false;
}

void solve()
{
	int i, count;
	count = 0;
	for (i = 2; i <= N; i++) {
		if (fun(i))
			count++;
	}
	printf("%d\n", count);
}

int main()
{
	init();
	solve();
	return 0;
}

//Answer:402
