#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

void show()
{
	int a, b, c;
	for (a = 1; a < 333; a++) {
		for (c = 333; c < 500; c++) {
			b = 1000 - a - c;
			if (a * a + b * b == c * c) {
				printf("%d\n", a * b * c);
				return;
			}
		}
	}
}

int main()
{
	show();
	return 0;
}
//Answer:31875000
