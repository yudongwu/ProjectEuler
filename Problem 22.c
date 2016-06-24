#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct str {
	char name[12];
};

char a[12];

int namevalue(char *s)
{
	int i, sum;
	i = sum = 0;
	while (s[i]) {
		sum += (s[i] - 'A' + 1);
		i++;
	}
	return sum;
}

int cmp(const void *a, const void *b)
{
	return strcmp((*(struct str *)a).name, (*(struct str *)b).name);
}

void solve(void)
{
	FILE *fp;
	int i, j, k;
	char *s, c;
	long long sum = 0;

	struct str namestring[5163];

	fp = fopen("names.txt", "r");
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
				strcpy(namestring[k++].name, a);
				memset(a, '\0', 12 * sizeof(char));
			}
		} else {
			a[j++] = c;
		}
	}
	strcpy(namestring[k].name, a);
	memset(a, '\0', 12 * sizeof(char));

	qsort(namestring, 5163, sizeof(namestring[0]), cmp);

	for (i = 0; i <= 5162; i++) {
		sum += (namevalue(namestring[i].name) * (i + 1));
	}
	printf("%lld\n", sum);
}

int main(void)
{
	solve();
	return 0;
}

//Answer:871198282
