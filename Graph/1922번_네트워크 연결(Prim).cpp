#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define INF 987654321
using namespace std;

int n, m, a, b, val;
bool added[1001]; // 트리에 포함 되어있는지
vector<P> vec[1001];
int prim() {
	vector<int> minVal(n + 1, INF);
	int ret = 0;
	minVal[1] = 0;
	for (int i = 1; i <= n; i++) {
		int u = -1, minV=INF;
		// 선택된 정점들(트리)과 연결가능한 가장 작은 비용이 드는 정점 u에 저장
		for (int j = 1; j <= n; j++) {
			if (!added[j] && (u==-1 || minV > minVal[j])) {
				u = j;
				minV = minVal[j];
			}
		}
		//minV가 INF라면 끊긴 그래프
		ret += minV;
		added[u] = true;
		// 새로 선택한 정점(u)과 연결되어있는 정점의 저장된 비용 갱신
		for (P &v : vec[u]) {
			if (!added[v.first] && minVal[v.first] > v.second) {
				minVal[v.first] = v.second;
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &a, &b, &val);
		vec[a].push_back({ b,val });
		vec[b].push_back({ a,val });
	}
	printf("%d", prim());

	return 0;
}