#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
int a[1230];

bool prim(int n)
{
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

void init()
{
	int i, j;
	i = 3;
	j = 1;
	a[0] = 2;
	while (j < 1230) {
		if (prim(i)) {
			a[j++] = i;
		}
		i += 2;
	}
}

bool judge(int a, int b, int c)
{
	char A[5], B[5], C[5];
	sprintf(A, "%d", a);
	qsort(A, 4, sizeof(char), cmp);
	sprintf(B, "%d", b);
	qsort(B, 4, sizeof(char), cmp);
	sprintf(C, "%d", c);
	qsort(C, 4, sizeof(char), cmp);
	if (strcmp(A, B) == 0 && strcmp(A, C) == 0)
		return true;
	return false;
}

void solve()
{
	int i, b, c, d;
	i = 0;
	init();
	while (a[i++] < 1000) ;
	for (; i < 1229; i++) {
		b = a[i];
		c = a[i] + 3330;
		d = a[i] + 6660;
		if (d < 9999) {
			if (prim(b) && prim(c) && prim(d)) {
				if (judge(b, c, d)) {
					printf("%d %d %d\n", b, c, d);
				}
			}
		}
	}

}

int main()
{
	solve();
	return 0;
}

//Answer:296962999629
