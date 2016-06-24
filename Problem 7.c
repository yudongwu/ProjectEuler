#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int prim(int n)
{
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void solve(int n)
{
	int i = 2;
	int count = 0;
	while (1) {
		if (prim(i)) {
			count++;
			if (count == n)
				break;
		}
		i++;
	}
	printf("%d\n", i);
}

int main()
{
	int n = 10001;
	solve(n);
	return 0;
}

//Answer:104743
