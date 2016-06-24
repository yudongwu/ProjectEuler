#include<stdio.h>

#define N 15
int main()
{
	char t[5];
	int s[N][N] = { 0 };
	FILE *f;
	int i, j;
	f = fopen("18.txt", "r");
	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			fgets(t, 4, f);
			s[i][j] = atoi(t);
		}
	}
	fclose(f);
	for (i = N - 2; i >= 0; i--) {
		for (j = 0; j <= i; j++) {
			if (s[i + 1][j] > s[i + 1][j + 1]) {
				s[i][j] += s[i + 1][j];
			} else {
				s[i][j] += s[i + 1][j + 1];
			}
		}
	}
	printf("answer: %d\n", s[0][0]);
	return 0;
}

//Answer:1074
