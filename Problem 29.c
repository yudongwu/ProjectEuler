#include <stdio.h>
#include <string.h>

const int prim[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
	43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
};

struct node {
	char list[100];

} num[9801];

int cmp(const void *a, const void *b)
{
	return strcmp((*(struct node *)a).list, (*(struct node *)b).list);
}

char *explain(int a, int b)
{								/*将a^b分解因数 */
	char s[100], ch;
	char *p;
	p = s;
	int t;
	for (int i = 0; i < 25; i++) {
		t = 0;
		while (a % prim[i] == 0) {
			if (t == 0) {
				sprintf(p, "%d", prim[i]);
			}
			a /= prim[i];
			t++;
		}
		if (t > 0) {
			p = s + strlen(s);
			*p++ = '^';
			t = t * b;
			sprintf(p, "%d", t);
			p = s + strlen(s);
			if (a != 1) {
				*p++ = '*';
			} else {
				break;
			}
		}
	}
	return s;
}

void solve(void)
{
	int i, j, k, sum;
	k = 0;
	for (i = 2; i < 101; i++) {
		for (j = 2; j < 101; j++) {
			strcpy(num[k++].list, explain(i, j));
		}
	}
	qsort(num, 9801, sizeof(num[0]), cmp);
	sum = 1;
	for (i = 0; i < 9801;) {
		j = i + 1;
		if (j >= 9801)
			break;
		while (strcmp(num[i].list, num[j].list) == 0) {
			j++;
		}
		i = j;
		sum++;
	}
	printf("%d\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
//method 2
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 101
#define M 601

int main(void)
{
	int answer = 0;
	int i, j, k, l;
	bool flag[M];

	bool use[N] = { false };

	for (i = 2; i < N; i++) {
		if (!use[i]) {
			int t = i;

			memset(flag, false, sizeof(flag));

			for (j = 2; j < N; j++) {
				t = t * i;
				if (t >= N) {
					break;
				}
				use[t] = true;
			}

			for (k = 1; k < j; k++) {
				for (l = 2; l < N; l++) {
					flag[k * l] = true;
				}
			}

			for (k = 2; k < M; k++) {
				if (flag[k]) {
					answer++;
				}

			}
		}
	}
	printf("%d\n", answer);
	return 0;
}

//Answer:9183
