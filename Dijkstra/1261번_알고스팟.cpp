/*
벽을 부숴 n,m까지 가는데에 최소한의 벽을 부수는 문제
벽을 가중치로 두어 0,0 에서 n,m까지 갈 때의 최솟값을 출력했다.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int n, m;
char arr[101][101];
int dis[101][101];    //최단거리 저장
int goX[4] = { 0,0,-1,1 };
int goY[4] = { -1,1,0,0 };
void dijkstra(int x,int y) {
	// 뒤는 목적지 좌표, 앞은 목적지까지 거리 저장
	priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
	pair<int, pair<int,int>> tmp, next;
	for (int i = 0; i < m; i++)
		fill(dis[i], dis[i] + n, INF);
	dis[x][y] = 0;
	q.push(make_pair(0, make_pair(x,y)));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < 4; j++) {
			int nextX = tmp.second.first + goX[j];
			int nextY = tmp.second.second + goY[j];
			if (nextX <0 || nextX>m - 1 || nextY<0 || nextY>n - 1) continue;

			int nextis = arr[nextX][nextY] == '1' ? 1 : 0;
			if (dis[nextX][nextY] <= tmp.first) continue;
			if (tmp.first + nextis < dis[nextX][nextY]) {
				dis[nextX][nextY] = tmp.first + nextis;
				q.push(make_pair(dis[nextX][nextY],make_pair(nextX,nextY))); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%s", arr[i]);
	}
	dijkstra(0,0);
	printf("%d", dis[m - 1][n - 1]);

	return 0;
}