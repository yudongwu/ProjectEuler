#include<stdio.h>
#include<stdbool.h>

int a[1002];

bool prim(int n)
{
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

void init()
{
	int i, j;
	i = 3;
	j = 1;
	a[0] = 2;
	while (j < 1000) {
		if (prim(i))
			a[j++] = i;
		i += 2;
	}
}

bool judge(int n)
{
	int i, flag, count;
	count = flag = 0;

	for (i = 0; i < 1000; i++) {
		while (n % a[i] == 0) {
			flag = 1;
			n = n / a[i];
		}
		if (flag)
			count++;
		flag = 0;
		if (count == 4)
			return true;
	}
	return false;
}

void solve()
{
	int i;
	for (i = 20; i < 1000000;) {
		if (judge(i)) {
			if (judge(i + 1)) {
				if (judge(i + 2)) {
					if (judge(i + 3)) {
						printf("%d %d %d %d\n", i, i + 1, i + 2, i + 3);
						return;
					} else {
						i += 4;
						continue;
					}
				} else {
					i += 3;
					continue;
				}
			} else {
				i += 2;
				continue;
			}
		} else {
			i++;
		}
	}
}

int main()
{
	init();
	solve();
	return 0;
}

//Answer:134043
