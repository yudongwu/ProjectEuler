#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool test(int n)
{
	int m;
	m = (int)sqrt(n * 2);
	if (m * (m + 1) == 2 * n)
		return true;
	else
		return false;
}

int count(char *s)
{
	int i = 0;
	int sum = 0;
	while (s[i] != '\0') {
		sum += s[i] - 'A' + 1;
		i++;
	}
	return sum;
}

void solve(void)
{
	FILE *fp;
	int i, j, k;
	char *s, c;
	int sum = 0;
	char a[20];

	fp = fopen("words.txt", "r");
	fseek(fp, 0, SEEK_END);
	int file_size;
	file_size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	s = (char *)malloc(file_size * sizeof(char));
	fread(s, sizeof(char), file_size, fp);

	i = j = k = 0;
	while (i <= file_size) {
		c = s[i++];
		if (!isalpha(c)) {
			if (c == ',') {
				j = 0;
				if (test(count(a)))
					sum++;
				memset(a, '\0', 20 * sizeof(char));
			}
		} else {
			a[j++] = c;
		}
	}
	if (test(count(a)))
		sum++;
	memset(a, '\0', 20 * sizeof(char));

	printf("%d\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

//Answer:162
