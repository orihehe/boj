/*
처음에 1을 기준으로 가장 멀리 있는 노드를 찾는다.
다음으로 가장 멀리 있는 노드를 기준으로 그 노드에서 가장 먼 노드를 찾아 거리를 출력해준다.
*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int visited[100001];
int far[100001];
vector<vector<pair<int,int>>> vec;
int farnode = 1;
int maxdis = 0;
void dfs(int start) {
	visited[start] = 1;
	int len = vec[start].size();
	for (int i = 0; i < len; i++) {
		pair<int,int> next = vec[start][i];
		if (visited[next.first] == 1) {
			continue;
		}
		far[next.first] += far[start]+next.second;
		dfs(next.first);
	}
	if (maxdis < far[start]) {
		maxdis = far[start];
		farnode = start;
	}
	return;
}

int main(void) {
	int n, now, nn, distance;

	scanf("%d", &n);
	vec.resize(n+1);

	for (int i = 0; i < n; i++) {
		scanf("%d", &now);
		nn = 0;
		while (nn != -1) {
			scanf("%d", &nn);
			if (nn != -1) {
				scanf("%d", &distance);
				vec[now].push_back(make_pair(nn, distance));
			}
		}
	}
	dfs(1);
	maxdis = 0;

	memset(visited, 0, sizeof(visited));
	memset(far, 0, sizeof(far));

	dfs(farnode);
	printf("%d", maxdis);

	return 0;
}