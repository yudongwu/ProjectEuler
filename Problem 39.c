#include <stdio.h>

int count(int p)
{
	int a, b, c, n, p1, p2;
	n = 0;
	p1 = p / 3;
	p2 = p / 2;
	for (a = 1; a < p1; a++) {
		for (b = p2 - a; b < p2; b++) {
			c = p - a - b;
			if (a * a + b * b == c * c) {
				n++;
			}
		}
	}
	return n;
}

int main()
{
	int i, max, t, k;
	max = 3;
	for (i = 120; i < 1000; i++) {
		t = count(i);
		if (t > max) {
			max = t;
			k = i;
		}
	}
	printf("%d\n", k);
	return 0;
}

//Answer:840
