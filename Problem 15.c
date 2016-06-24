#include<iostream>
#include<cmath>
using namespace std;

long long a[21][21];

int main()
{
	int i;
	for (i = 0; i < 21; i++) {
		a[0][i] = 1;
		a[i][0] = 1;
	}
	for (i = 1; i < 21; i++)
		for (int j = 1; j < 21; j++)
			a[i][j] = a[i][j - 1] + a[i - 1][j];
	cout << a[20][20] << endl;
	return 0;
}

//Answer:137846528820
