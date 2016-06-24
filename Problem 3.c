#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define N 600851475143

bool prim(int n)
{
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	long long s = sqrt(N);
	while (s--) {
		if (s % 2 != 0 && prim(s) && (N % s == 0)) {

			printf("%lld\n", s);
			break;
		}
	}
	return 0;
}

//Answer:6857
