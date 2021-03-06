#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int arr[8][8];
int tmpArr[8][8];
int n, m, sum, maxSum;
int rgo[4] = { 0,0,1,-1 };
int cgo[4] = { 1,-1,0,0 };
vector<pair<int, int>> vec;  // 바이러스 위치 저장

void arr_copy() { // 바이러스 퍼지기 전 arr 카피
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmpArr[i][j] = arr[i][j];
		}
	}
}

void dfs(int r,int c) {  // 바이러스 퍼짐
	arr[r][c] = 2;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i];
		int nc = c + cgo[i];
		if (nr < 0 || nc<0 || nr >= n || nc>=m) continue;
		if (arr[nr][nc] == 0) {
			dfs(nr, nc);
		}
	}
}

void make_wall(int wcnt) { // wcnt는 벽 개수
	if (wcnt == 3) {
		arr_copy();
		for (int i = 0; i < vec.size(); i++) {
			dfs(vec[i].first, vec[i].second);
		}
		sum = 0;
		for (int i = 0; i < n; i++) {  // 안전구역 셈
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0)
					sum++;
			}
		}
		maxSum = max(maxSum, sum);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = tmpArr[i][j];
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {  // 벽 세우기 모든 경우
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				make_wall(wcnt+1);
				arr[i][j] = 0;
			}
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2) {
				vec.push_back({ i,j });
			}
		}
	}
	make_wall(0);
	printf("%d", maxSum);

	return 0;
}
