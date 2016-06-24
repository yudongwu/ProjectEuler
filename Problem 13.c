#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int a[100][50];
int b[100];
void init()						//将“number.txt”中的数据数据读入a[][]中
{
	int i, j, k, len;
	char c;
	string s;
	ifstream fin;
	fin.open("number.txt");
	while ((c = fin.get()) != EOF) {
		s.push_back(c);
	}
	len = s.size();
	k = 0;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 50; j++) {
			if (s[k] != '\n')
				a[i][j] = s[k++] - '0';
		}
		k++;
	}
}

void solve()
{
	init();
	int i, j, s, t, r, k, flag;
	s = flag = k = 0;
	for (j = 49; j >= 0; j--) {
		s += flag;
		flag = 0;
		for (i = 0; i < 100; i++)
			s += a[i][j];
		flag = s / 10;
		t = s % 10;
		b[k++] = t;
		if (j == 0)
			b[k] = flag;
		s = 0;
	}
	for (i = k; i > k - 9; i--)
		cout << b[i];
}

int main()
{
	solve();
	return 0;
}

//Answer:5537376230
