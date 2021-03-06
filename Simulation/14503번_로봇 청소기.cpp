#include <cstdio>
using namespace std;

int arr[50][50];
int rgo[4] = { -1,0,1,0 };
int cgo[4] = { 0,1,0,-1 };

int main()
{
	// r,c = 현재위치 d = 방향
	int n, m, r, c, d, i;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &r, &c, &d);
	for (i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//2는 청소함 1은 벽 
	int cnt, result=1;
	while (true) {
		arr[r][c] = 2;
		cnt = 3;
		do {
			int nr = r + rgo[(cnt + d) % 4];
			int nc = c + cgo[(cnt + d) % 4];
			if (arr[nr][nc]==0) {  // 청소 안한곳
				r = nr;
				c = nc;
				d = (cnt + d) % 4;
				break;
			}
			cnt--;
		} while (cnt >= 0);
		if (cnt==-1) { // 청소할 곳 없음
			//뒤가 벽
			if (arr[r + rgo[(d + 2) % 4]][c + cgo[(d + 2) % 4]] == 1) {
				break;
			}
			else {
				r += rgo[(d + 2) % 4];
				c += cgo[(d + 2) % 4];
			}
		}
		else {
			result++;
		}
	}
	printf("%d", result);

	return 0;
}