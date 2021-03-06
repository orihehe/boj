#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k, arr[101][101], cnt, area;
void dfs(int i, int j) {
	if (i > 0 && arr[i - 1][j] == 0) {
		arr[i - 1][j]++; area++;
		dfs(i - 1, j);
	}
	if (i < n - 1 && arr[i + 1][j] == 0) {
		arr[i + 1][j]++; area++;
		dfs(i + 1, j);
	}
	if (j > 0 && arr[i][j - 1] == 0) {
		arr[i][j - 1]++; area++;
		dfs(i, j - 1);
	}
	if (j < m - 1 && arr[i][j + 1] == 0) {
		arr[i][j + 1]++; area++;
		dfs(i, j + 1);
	}
}

int main()
{
	int x1, y1, x2, y2; // 1은 왼쪽아래 2는 오른 위
	vector<int> vec;
	scanf("%d %d %d", &m, &n, &k);
	while (k--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++) { // 직사각형 범위 표시
			for (int j = y1; j < y2; j++) {
				arr[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) { // 빈공간 세기
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				area=1;
				arr[i][j]++;
				dfs(i, j);
				cnt++; // 빈공간 개수
				vec.push_back(area); // vec에 빈공간 크기 저장
			}
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d\n", cnt);
	for (auto v : vec) printf("%d ", v);

	return 0;
}