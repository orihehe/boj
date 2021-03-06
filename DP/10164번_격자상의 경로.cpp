/*
동그라미가 존재한다면 0,0 -> 동그라미 경우의 수 * 동그라미 -> (n,m) 경우의 수가 답이다.
동그라미가 없다면 0,0->n,m
경로의 수는 i,j = i-1,j + i,j-1 이다
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, x, arr[15][15];
int init(int str,int stc,int rr,int cc) {
	for (int i = str; i <= rr; i++) {
		arr[i][stc] = 1;
	}
	for (int i = stc; i <= cc; i++) {
		arr[str][i] = 1;
	}
	for (int i = str+1; i <= rr; i++) {
		for (int j = stc+1; j <= cc; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
	return arr[rr][cc];
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	if (x == 0) {
		init(0,0,n-1, m-1);
		printf("%d", arr[n - 1][m - 1]);
	}
	else {
		int r=(x-1)/m, c=(x-1)%m;
		int tmp;
		tmp = init(0,0,r, c);
		init(r, c, n-1, m-1);
		printf("%d", tmp*arr[n - 1][m - 1]);
	}

	return 0;
}