/*
속도를 더 빨리 하려면
arr[i][j]+=arr[i][j-1]+arr[i-1][j]+arr[i-1][j-1]을 하고
x1,y1 / x2,y2 좌표가 주어지면
arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1]+arr[x1-1][y1-1]을 하면 된다
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int main()
{
	int r, c, q, r1, c1, r2, c2, cnt = 0, sum = 0;
	scanf("%d %d %d", &r, &c, &q);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	}
	while (q--) {
		sum = 0;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		cnt = (r2 - (r1 - 1)) * (c2 - (c1 - 1));
		for (int i = r1; i <= r2; i++) {
			sum += arr[i][c2] - arr[i][c1 - 1];
		}
		printf("%d\n", sum / cnt);
	}

	return 0;
}