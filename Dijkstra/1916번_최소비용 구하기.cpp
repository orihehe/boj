#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int v, e, u, s, w, from, to;
vector<pair<int, int>> vec[20001];  // pair 앞은 목적지, 뒤는 가중치
int dis[20001];    //최단거리 저장
void dijkstra(int start) {
	// 우선순위 큐 뒤는 목적지, 앞은 목적지까지 거리
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	pair<int, int> tmp, next;
	fill(dis, dis + v + 1, INF);
	dis[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < vec[tmp.second].size(); j++) {
			next = vec[tmp.second][j];
			if (dis[next.first] <= tmp.first) continue;
			if (tmp.first + next.second < dis[next.first]) {
				dis[next.first] = tmp.first + next.second;
				q.push(make_pair(dis[next.first], next.first)); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}

int main()
{
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &s, &w);
		vec[u].push_back(make_pair(s, w));
	}
	scanf("%d %d", &from, &to);
	dijkstra(from);
	printf("%d", dis[to]);

	return 0;
}