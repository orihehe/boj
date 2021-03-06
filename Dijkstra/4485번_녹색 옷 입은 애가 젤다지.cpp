#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 987654321
#define pp pair<int,int>
using namespace std;

int m;
int arr[125][125];
int dis[125][125];    //최단거리 저장
int goX[4] = { 0,0,-1,1 };
int goY[4] = { -1,1,0,0 };
void dijkstra(int x, int y) {
	// 뒤는 목적지 좌표, 앞은 목적지까지 거리 저장
	priority_queue<pair<int, pp>, vector<pair<int, pp>>, greater<pair<int, pp>>> q;
	pair<int, pp> tmp, next;
	for (int i = 0; i < m; i++)
		fill(dis[i], dis[i] + m, INF);
	dis[x][y] = arr[x][y];
	q.push(make_pair(arr[x][y], make_pair(x, y)));
	while (!q.empty()) {
		tmp = q.top();
		q.pop();
		for (int j = 0; j < 4; j++) {
			int nextX = tmp.second.first + goX[j];
			int nextY = tmp.second.second + goY[j];
			if (nextX <0 || nextX>m - 1 || nextY<0 || nextY>m - 1) continue;

			int nextis = arr[nextX][nextY];
			if (dis[nextX][nextY] <= tmp.first) continue;
			if (tmp.first + nextis < dis[nextX][nextY]) {
				dis[nextX][nextY] = tmp.first + nextis;
				q.push(make_pair(dis[nextX][nextY], make_pair(nextX, nextY))); // 다음 목적지까지의 가중치, 목적지 
			}
		}
	}
}

int main()
{
	int pro = 1;
	scanf("%d", &m);
	while (m != 0) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dijkstra(0, 0);
		printf("Problem %d: %d\n", pro++,dis[m - 1][m - 1]);
		scanf("%d", &m);
	}

	return 0;
}