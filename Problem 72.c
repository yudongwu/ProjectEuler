#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define N 1000001

bool a[N];

void Eratosthenes()
{
	int i, M, j;
	for (i = 2; i < N; i++) {
		a[i] = true;
	}
	M = (int)sqrt(N);
	for (i = 2; i <= M; i++) {
		if (a[i]) {
			j = i * i;
			for (; j < N; j += i)
				a[j] = false;
		}
	}
}

int fun(int n)
{
	int t, i, count, j;
	t = n / 2;
	i = 2;
	count = n - 1;
	while (i <= t) {
		if (a[i]) {
			if (n % i == 0) {
				count--;
				for (j = i; j * i < n; j++) {
					count--;
				}
			}
		}
		i++;
	}
	return count;
}

int main()
{
	int i;
	long long count = 0;

	Eratosthenes();

	for (i = 2; i < N; i++) {
		if (a[i]) {
			count += i - 1;
		} else {
			count += fun(i);
		}
	}
	printf("%lld\n", count);

	return 0;
}

//Answer:303963552391
