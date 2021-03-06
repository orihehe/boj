/*
역방향 그래프를 만들고 bfs로 추적한다.
도착지서부터 bfs시작하여 다음 노드에 저장되어있는 최단거리 + 가중치가 
현재 노드에 저장되어있는 최단거리와 같다면 그 길을 통해 온것이다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define pp pair<int,int>
#define INF 987654321
using namespace std;

int v, e, u, s, w, from, to;
vector<pp> vec[1001], rev[1001];  // pair 앞은 목적지, 뒤는 가중치
int dis[1001];    //최단거리 저장
void dijkstra(int start) {
	// 우선순위 큐 뒤는 목적지, 앞은 목적지까지 거리
	priority_queue<pp, vector<pp>, greater<pp>> q;
	pp tmp, next;
	fill(dis, dis + v + 1, INF);
	dis[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < vec[tmp.second].size(); j++) {
			next = vec[tmp.second][j];
			int cost = tmp.first + next.second;
			if (dis[next.first] <= tmp.first) continue;
			if (cost < dis[next.first]) {
				dis[next.first] = cost;
				q.push(make_pair(dis[next.first], next.first)); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}
int cnt;
stack<int> sta;
void bfs(int start,int end) {
	queue<int> q;
	q.push(end); 
	sta.push(end);
	cnt++;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == start)continue;
		for (auto n : rev[here]) {
			int next = n.first;
			if (dis[here] == dis[next] + n.second) {
				sta.push(next);
				cnt++;
				q.push(next);
				break;
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
		rev[s].push_back({ u,w }); // 역방향 그래프
	}
	scanf("%d %d", &from, &to);
	dijkstra(from);
	printf("%d\n", dis[to]);
	bfs(from, to);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", sta.top());
		sta.pop();
	}

	return 0;
}