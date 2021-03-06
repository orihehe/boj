#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define pp pair<int,int>
#define INF 1000000
using namespace std;

int v, e, u, s, w, mustA,mustB;
vector<pp> vec[801];  // pair 앞은 목적지, 뒤는 가중치
int dis[801];    //최단거리 저장
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

int main()
{
	int AtoB=0, BtoA=0;  // AtoB = 1->A->B->v, BtoA = 1->B->A->v
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &s, &w);
		//양방향
		vec[u].push_back({ s,w });
		vec[s].push_back({ u,w });
	}
	scanf("%d %d", &mustA, &mustB);
	dijkstra(1);
	AtoB += dis[mustA];  // 1->A
	BtoA += dis[mustB];  // 1->B
	dijkstra(mustA);
	AtoB += dis[mustB]; // A->B
	BtoA += dis[v];  // A->v
	dijkstra(mustB);
	AtoB += dis[v];  // B->v
	BtoA += dis[mustA];   // B->A
	//더한 값에 INF가 하나라도 있으면 경로 없음
	if (AtoB >= INF && BtoA >= INF) printf("-1");
	else {
		if (AtoB > BtoA) printf("%d", BtoA);
		else printf("%d", AtoB);
	}


	return 0;
}