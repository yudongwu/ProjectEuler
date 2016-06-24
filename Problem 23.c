#include <iostream>
using namespace std;
int sum(int x)
{
	int xx = x / 2, sum = 0;
	for (int i = 1; i <= xx; i++)
		(x % i == 0) ? sum += i : sum = sum;
	return sum;
}
void main()
{
	int b[28124] = { 0 }, c[28124] = {
	0}, x = 0;
	for (int i = 2; i <= 28123; i++) {
		x = sum(i);
		if (x > i)
			b[i] = 1;
	}
	for (int i = 2; i <= 28123; i++)
		for (int j = 2; j <= 28123 - i; j++)
			if (c[i + j] != 2)
				c[i + j] = b[i] + b[j];
	for (int i = 2; i <= 28123; i++)
		if (c[i] != 2)
			x += i;
	cout << x << endl << endl;
}

//Answer:4179871
