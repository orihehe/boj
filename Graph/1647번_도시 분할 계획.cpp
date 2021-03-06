/*
최소 스패닝 트리를 구한 뒤 유지비가 가장 큰 간선 하나를 없애면 유지비 합이 최소인 두 마을로 분리된다.
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define INF 987654321
#define ll long long
using namespace std;

int n, m, a, b, val, maxval=0;
bool added[100001]; // 트리에 포함 되어있나
vector<P> vec[100001];
int prim() {
	priority_queue<P, vector<P>, greater<P>> pq; // P : 비용, 정점
	int ret = 0;
	pq.push({ 0,1 });
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
		ret += minV;
		maxval = max(maxval, minV);
		added[u] = true;
		// 새로 선택한 정점과 연결되어있는 정점 push
		for (P &v : vec[u]) {
			if (!added[v.first]) {
				pq.push({ v.second,v.first });
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &val);
		vec[a].push_back({ b,val });
		vec[b].push_back({ a,val });
	}
	printf("%d", prim()-maxval);

	return 0;
}