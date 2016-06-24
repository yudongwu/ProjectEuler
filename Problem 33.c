#include<stdio.h>
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int gcd(int a, int b)
{
	int r;
	if (a < b)
		swap(&a, &b);
	if (!b)
		return a;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}

void find()
{
	int i;
	int M, N;
	M = N = 1;
	for (i = 12; i < 50; i++) {
		for (int j = i + 1; j < 100; j++) {
			int t = gcd(i, j);
			if (t == 1 || i / t > 10 || j / t > 10 || i % 10 != j / 10)
				continue;
			else {
				int a = i / 10, b = j % 10;
				if (a / gcd(a, b) == i / t && b / gcd(a, b) == j / t) {
					M *= i / t;
					N *= j / t;
				}
			}
		}
	}
	printf("%d\n", N / gcd(M, N));
}

int main()
{
	find();
	return 0;
}

//Answer:100
