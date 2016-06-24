#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 4000000

int a[1001];

void solve()
{
	int a, b, c, n, count = 2;
	a = 1, c = 0, b = 2;
	n = 3;
	while (c <= N) {
		c = a + b;
		if (n % 2 != 0) {
			a = c;
		} else {
			b = c;
		}
		n++;
		if (c % 2 == 0) {
			count += c;
		}
	}
	printf("%d", count);
}

int main()
{
	solve();
	return 0;
}

//Answer:4613732
