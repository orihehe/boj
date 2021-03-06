/*
3중 포문으로 모든 경우를 보는 것이다.
계속 생각해봐도 모르겠어서 찾아봤는데 잘 이해가 되진 않는다. 나중에 다시 풀어볼것이다.
sum배열에는 sum[i]는 novel[1]~novel[i]까지의 합이 들어있다.
dp[i][j]는 i번째파일~j번째 파일을 합쳤을때의 최소비용이 들어가있다.
1~2, 2~3 처럼 1페이지 차이 부터 시작하여 
1~3, 2~4
1~4, 2~5
1~N을 구하는 것이다.
dp[tx][ty] = min(dp[tx][ty], 
				dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
이 부분은 dp[tx][mid] + dp[mid + 1][ty]에서 dp[tx][mid]경우와
dp[mid + 1][ty] 경우를 합쳤을 때 sum[ty] - sum[tx - 1]비용이 추가로 발생한다.
만약 이때 이 전의 경우의 최솟값보다 작으면 현재 경우가 더 비용이 덜 발생하는 경우이고
그래서 값을 바꿔준다.
주석을 쓰다보니 이해가 됐는데 내가 이걸 생각해내고 짜기가 어려운거같다.
다시 풀어봐야지..
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t, k, x;
int dp[501][501];
int novel[501];
int sum[501];
int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", &novel[i]);
			sum[i] = sum[i - 1] + novel[i];
		}
		for (int d = 1; d < k; ++d) {
			for (int tx = 1; tx + d <= k; ++tx) {
				int ty = tx + d;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; ++mid)
					dp[tx][ty] =
					min(dp[tx][ty],
						dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		} 
		printf("%d\n", dp[1][k]);
	}

	return 0;
}