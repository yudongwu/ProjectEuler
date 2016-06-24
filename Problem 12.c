#include <stdio.h>
#include <stdbool.h>

int trinumber(int n)
{
	if (n % 2 == 0) {
		return (n / 2) * (n + 1);
	} else {
		return ((n + 1) / 2) * n;
	}
}

bool divnum(int n)
{
	int i, sum = 0;
	for (i = 1; i * i < n; i++) {
		if (n % i == 0) {
			sum += 2;
		}
	}
	if (i * i == n)
		sum++;
	if (sum > 500)
		return true;
	else
		return false;
}

void solve(void)
{
	int i, num;
	num = 0;
	for (i = 1;; i++) {
		if (divnum(trinumber(i))) {
			printf("%d\n", trinumber(i));
			break;
		}
	}
}

int main(void)
{
	solve();
	return 0;
}

//Answer:76576500
