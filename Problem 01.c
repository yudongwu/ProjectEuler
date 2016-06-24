#include <stdio.h>
#include <string.h>
#include <ctype.h>

void solve()
{
	int sum, i;
	sum = 0;
	for (i = 3; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("%d\n", sum);

}

int main()
{
	solve();
	return 0;
}

//Answer:233168
