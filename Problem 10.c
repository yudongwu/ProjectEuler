#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define N 2000000

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
	int i;
	long long sum = 2;
	for (i = 3; i <= N; i = i + 2) {
		if (prim(i)) {
			sum += i;
		}
	}
	printf("%lld\n", sum);

	return 0;
}

//Answer:142913828922
