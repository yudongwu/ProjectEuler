#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#define N 10000000

int phi[N];						//�����д���ÿ������ŷ����

int cmp(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

void genPhi(int n)				//�����nС��ÿһ������ŷ����(n-1��)
{
	int i, j, pNum = 0;
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for (i = 2; i < n; i++) {
		if (!phi[i]) {
			for (j = i; j < n; j += i) {
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int fun(int n)					//��������n��λ��
{
	return (log10(n * 1.0) + 1);
}

bool compare(int n, int m)		//�ж��������Ƿ�����һ������һ����������
{
	int i, L1, L2;
	char from[10], to[10];
	sprintf(from, "%lld", m);
	sprintf(to, "%lld", n);
	L1 = strlen(from);
	L2 = strlen(to);
	qsort(from, L1, sizeof(from[0]), cmp);
	qsort(to, L2, sizeof(to[0]), cmp);
	return !strcmp(from, to);
}

void solve()
{
	int i, j, count, k;
	double min, t;
	min = 10.0;
	for (i = 2; i < N; i++) {
		if ((fun(i) == fun(phi[i])) && compare(i, phi[i])) {
			t = i * 1.0 / phi[i];
			if (t < min) {
				min = t;
				k = i;
			}
		}
	}
	printf("%d\n", k);
}

int main()
{
	genPhi(N);
	solve();
	return 0;
}

//Answer:8319823
