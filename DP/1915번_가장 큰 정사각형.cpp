/*
num[i][j]를 오른쪽 아래 각으로 하는 가장 큰 정사각형의 변의 길이로 둔다.
변의 길이가 3인 정사각형의 경우
1 1 1    <- num배열에 이런식으로 저장이 된다. 
1 2 2
1 2 3
위, 왼, 위왼대각 에서 n의 변을 가진 정사각형을 만들 수 있고, 현재위치 값이 1이라면
n+1의 변을 가진 정사각형을 만들 수 있게 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int num[1001][1001];
char dd[1002][1002];
int main() {
	int maxC=0;
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", dd[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			num[i+1][j+1] = dd[i][j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(num[i][j]==1)
				num[i][j] = min({ num[i - 1][j - 1],num[i - 1][j],num[i][j - 1] })+1;
			maxC = max(maxC, num[i][j]);
		}
	}
	printf("%d", maxC*maxC);

	return 0;
}