/*
위상정렬로 푸는 방법이다.
들어오는 간선(indegree)의 수가 0인 정점을 큐에 모두 넣는다.
큐를 pop 하고 그 정점과 이어진 정점의 indegree를 -1해준다. 그때 0이된다면 큐에 push,
time 배열에 현재 건물을 짓기위해 기다리는 시간이 저장된다.
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int bd[1001];
int indegree[1001];
int time[1001];
vector<vector<int>> vec;

int main() {
	int t, n, k, a, b;
	scanf("%d", &t);
	while (t--) {
		queue<int> q;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &bd[i]);
		}
		vec.clear();
		vec.resize(n + 1);
		fill(indegree, indegree + n + 1, 0);
		fill(time, time + n + 1, 0);
		while (k--) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			indegree[b]++;
		}
		scanf("%d", &a);
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			for (int &v : vec[tmp]) {
				indegree[v]--;
				time[v] = max(bd[tmp] + time[tmp], time[v]);
				if (indegree[v] == 0)
					q.push(v);
			}
		}
		printf("%d\n", time[a] + bd[a]);
	}

	return 0;
}