#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool isprim(int n)
{
	int i = 2;
	if (n == 1)
		return false;
	for (; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool pandigital(int n)
{
	char s[10], d[10] = { 0 };
	int i = 0;
	sprintf(s, "%d", n);
	int len = strlen(s);
	while (i < len) {
		switch (s[i] - '0') {
		case 1:
			d[1] ++;
			break;
		case 2:
			d[2] ++;
			break;
		case 3:
			d[3] ++;
			break;
		case 4:
			d[4] ++;
			break;
		case 5:
			d[5] ++;
			break;
		case 6:
			d[6] ++;
			break;
		case 7:
			d[7] ++;
			break;
		case 8:
			d[8] ++;
			break;
		case 9:
			d[9] ++;
			break;
		default:
			break;
		}
		i++;
	}
	for (i = 1; i <= len; i++) {
		if (d[i] != 1)
			return false;
	}
	if (!isprim(n))
		return false;
	else
		return true;
}

int main()
{
	int i = 10000001;
	while (i > 1000) {
		if (pandigital(i)) {
			printf("%d\n", i);
			break;
		}
		i = i - 2;
	}
	return 0;
}

//Answer:7652413
