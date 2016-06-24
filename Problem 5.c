#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 20

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a / (gcd(a, b)) * b;
}

void solve()
{
	int i, s = 2;
	for (i = 3; i <= N; i++) {
		s = lcm(s, i);
	}
	printf("%d\n", s);
}

int main()
{
	solve();
	return 0;
}

//Answer:232792560
