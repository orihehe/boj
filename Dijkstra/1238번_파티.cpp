/*
역방향 그래프를 통해 집에서 x로 가는 최단거리를 구할 수 있다고 하는데
이해가 안 돼서 그래프를 그려보니 이해가 됐다. 
처음에 풀때는 배열 하나를 만들어서 x->집으로 가는 최단경로를 구해 저장하고,
각 집에서 x를 가는 최단경로를 따로 구했다.
하지만 역방향 그래프를 하나 더 만들어서 x에서 집들의 최단경로를 구하면 그것이
집에서 x로의 최단경로였다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define pp pair<int,int>
using namespace std;

int n,m,x, b,e,t, from, to;
vector<pp> vec[1001], vecHome[1001];  // pair 앞은 목적지, 뒤는 가중치
int dis[1001];    //최단거리 저장
int disHome[1001];
void dijkstra(vector<pp> ve[], int start, int arr[]) {
	// 우선순위 큐 뒤는 목적지, 앞은 목적지까지 거리
	priority_queue<pp, vector<pp>, greater<pp>> q;
	pair<int, int> tmp, next;
	fill(arr, arr + n + 1, INF);
	arr[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < ve[tmp.second].size(); j++) {
			next = ve[tmp.second][j];
			if (arr[next.first] <= tmp.first) continue;
			if (tmp.first + next.second < arr[next.first]) {
				arr[next.first] = tmp.first + next.second;
				q.push(make_pair(arr[next.first], next.first)); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}

int main()
{
	int maxlong = 0;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &b, &e, &t);
		vec[b].push_back(make_pair(e, t));
		vecHome[e].push_back({ b,t });
	}
	dijkstra(vec, x, dis);
	dijkstra(vecHome, x, disHome);
	for (int i = 1; i <= n; i++) {
		if (dis[i]+disHome[i] > maxlong)maxlong = dis[i] + disHome[i];
	}
	printf("%d", maxlong);

	return 0;
}