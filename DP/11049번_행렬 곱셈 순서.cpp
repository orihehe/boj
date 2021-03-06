/*
파일 합치기 문제랑 비슷했다.
*/
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> arr[500];
int dp[500][500];
int main()
{
	int n, r, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &r, &c);
		arr[i] = { r,c };
	}
	if (n == 1) {
		printf("%d", arr[0].first*arr[0].second);
		return 0;
	}
	for (int k = 1; k < n; k++) { // 범위
		for (int i = 0; i+k < n; i++) {
			dp[i][i + k] = INT_MAX;
			for (int mid = i; mid < i+k; mid++) {
				dp[i][i + k] = min(dp[i][i + k],
					dp[i][mid] + dp[mid + 1][i + k] + arr[i].first * arr[mid].second * arr[i + k].second);
			}
		}
	}
	printf("%d", dp[0][n - 1]);

	return 0;
}