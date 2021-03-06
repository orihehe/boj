/*
처음에 n,m중 3미만 수가 있다면 -1을 출력했지만, 미만이더라도 두 행렬이 같다면
0을 출력해야 했다.
푼 방법은 3x3행렬의 가장 왼쪽 위만을 비교하여 두개가 다르다면 나머지 부분을 모두
바꿔주는 방식이다. 모두 바꿔준 후 두 행렬을 비교하여 다르면 -1 같으면 바꾼 횟수를
출력해주었다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

char arrA[51][51], arrB[51][51];
int cnt;
void toggle(int x,int y) {
	for (int i = x; i < x+3; i++) {
		for (int j = y; j < y+3; j++) {
			arrA[i][j] == '0' ? arrA[i][j] = '1' : arrA[i][j] = '0';
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arrA[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", arrB[i]);
	}
	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			if (strcmp(arrA[i], arrB[i]) != 0) {
				printf("-1");
				return 0;
			}
		}
		printf("0"); return 0;
	}
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (arrA[i][j] != arrB[i][j]) {
				toggle(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (strcmp(arrA[i], arrB[i]) != 0) {
			printf("-1");
			return 0;
		}
	}
	printf("%d", cnt);

	return 0;
}