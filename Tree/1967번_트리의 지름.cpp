/*
1에서부터 가장 먼 노드를 찾은 뒤 그 노드에서 가장 먼 노드를 다시 찾아 거리를 출력한다.
노드의 개수가 n이고, 부모노드 번호가 작은것, 부모노드 번호가 같다면 자식노드의 번호가
작은 것이 먼저 입력되므로, child가 n일때까지 입력을 받는다.
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
	int n, parent,child=0,value;

	scanf("%d", &n);
	vec.resize(n+1);

	while(child!=n) {
		scanf("%d %d %d", &parent, &child, &value);
		vec[parent].push_back(make_pair(child,value));
		vec[child].push_back(make_pair(parent, value));
	}

	dfs(1);
	maxdis = 0;

	memset(visited, 0, sizeof(visited));
	memset(far, 0, sizeof(far));

	dfs(farnode);
	printf("%d", maxdis);

	return 0;
}