/*
다음 목적지까지의 최단거리가 더 짧을 때 어디서 왔는지 저장해주는 배열을 하나 더 만든다
다익스트라를 마친 후 도착지에서부터 저장된 번호를 따라 역추적한다
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
vector<pp> vec[1001];  // pair 앞은 목적지, 뒤는 가중치
int dis[2][1001];    //최단거리 저장
void dijkstra(int start) {
	// 우선순위 큐 뒤는 목적지, 앞은 목적지까지 거리
	priority_queue<pp, vector<pp>, greater<pp>> q;
	pp tmp, next;
	fill(dis[0], dis[0] + v + 1, INF);
	dis[0][start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < vec[tmp.second].size(); j++) {
			next = vec[tmp.second][j];
			int cost = tmp.first + next.second;
			if (dis[0][next.first] <= tmp.first) continue;
			if (cost < dis[0][next.first]) {
				dis[0][next.first] = cost;
				dis[1][next.first] = tmp.second;
				q.push(make_pair(dis[0][next.first], next.first)); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}

int main()
{
	int cnt;
	stack<int> sta;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &s, &w);
		vec[u].push_back(make_pair(s, w));
	}
	scanf("%d %d", &from, &to);
	dijkstra(from);
	printf("%d\n", dis[0][to]);
	cnt = 1;
	for (int i = to; i != from; i = dis[1][i]) {
		cnt++;
		sta.push(i);
	}
	sta.push(from);
	printf("%d\n", cnt);
	while (!sta.empty()) {
		printf("%d ", sta.top());
		sta.pop();
	}

	return 0;
}