#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define INF 987654321
#define ll long long
using namespace std;

int n, m, a, b, val;
bool added[1001]; // 트리에 포함 되어있나
int arr[1000][1000];
ll prim() {
	priority_queue<P, vector<P>, greater<P>> pq; // P : 비용, 정점
	ll ret = 0;
	pq.push({ 0,0 });
	for (int i = 1; i <= n; i++) {
		int u = -1, minV = INF;
		while (!pq.empty()) {
			P tmp = pq.top();
			pq.pop();
			u = tmp.second; 
			if (!added[tmp.second]) {
				minV = tmp.first;
				break;
			}
		}
		//minV가 INF라면 끊긴 그래프
		ret += (ll)minV;
		added[u] = true;
		// 새로 선택한 정점과 연결되어있는 정점 push
		for (int i = 0; i < n;i++) {
			if (i == u)continue;
			if (!added[i]) {
				pq.push({ arr[u][i],i });
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%lld", prim());

	return 0;
}