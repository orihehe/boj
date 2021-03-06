#include <cstdio>
#include <algorithm>
using namespace std;

bool visited[10];
int minCost=10000001, n;
int arr[10][10];
// start=시작지점, cost=비용, cnt=거쳐온 도시 수
void dfs(int start, int cur, int cost, int cnt) {
	// 모든 도시를 거쳐왔고, 시작도시로 가는 길이 있을 때
	if (cnt == n) {
		if(arr[cur][start] != 0)
			minCost = min(minCost, cost+ arr[cur][start]);
		return;
	}
	//현재까지의 비용이 이미 최소비용을 넘었을 때
	if (cost >= minCost) return;
	for (int i = 0; i < n; i++) {
		//시작도시가 아니고, 방문하지 않았고, 현재 도시에서 가는경로 있다면
		if (i!=start && !visited[i] && arr[cur][i] != 0) {
			visited[i] = true;
			dfs(start, i, cost + arr[cur][i], cnt+1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		visited[i] = true;
		dfs(i, i, 0, 1);
		visited[i] = false;
	}
	printf("%d", minCost);

	return 0;
}