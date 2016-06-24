#include<stdio.h>

#define N 10000000

int fun(int n)
{
	int t, sum;
	sum = 0;
	while (n) {
		t = n % 10;
		sum += t * t;
		n /= 10;
	}
	return sum;
}

void solve(void)
{
	int i, sum, t;
	sum = 0;
	for (i = 2; i < N; i++) {
		t = fun(i);
		while (1) {
			if (t == 89) {
				sum++;
				break;
			} else if (t == 1) {
				break;
			} else {
				t = fun(t);
			}
		}
	}
	printf("%d\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

///////////////////////////////////////////////////////////
//method 2
#include <stdio.h>
#include <stdbool.h>

#define N 10000000

bool a[600] = { false };

int fun(int n)
{
	int t, sum;
	sum = 0;
	while (n) {
		t = n % 10;
		sum += t * t;
		n /= 10;
	}
	return sum;
}

void solve(void)
{
	int i, sum, t, temp;
	sum = 0;
	for (i = 2; i < N; i++) {
		t = fun(i);
		temp = t;
		if (a[temp]) {
			sum++;
		} else {
			while (1) {
				t = fun(t);
				if (a[t] || t == 89) {
					a[temp] = true;
					sum++;
					break;
				} else if (t == 1) {
					break;
				} else {
				}
			}
		}
	}
	printf("%d\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

//Answer:8581146
