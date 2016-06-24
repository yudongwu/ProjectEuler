#include <stdio.h>

int solve()
{
	int i, k, result, n, t, temp;
	int s[8], a[101];
	i = k = 0;
	n = result = 1;
	t = 0;
	while (1) {
		temp = n;
		i = 0;
		while (temp) {
			s[i++] = temp % 10;
			temp /= 10;
		}
		i--;
		while (i >= 0) {
			a[k] = s[i];
			t++;
			if (t == 1 || t == 10 || t == 100 || t == 1000 || t == 10000 || t == 100000 || t == 1000000) {
				result *= a[k];
				if (t == 1000000)
					return result;
			}
			if (k == 100) {
				k = 1;
			} else {
				k++;
			}
			i--;
		}
		n++;
	}
}

int main(void)
{
	printf("%d\n", solve());
	return 0;
}

//Answer:210
