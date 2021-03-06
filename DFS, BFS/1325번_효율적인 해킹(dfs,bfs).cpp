#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int num[10001], cnt, visited[10001], value[10001];
vector<vector<int>> vec;
void dfs(int start) {
	int len = vec[start].size();
	for (int i = 0; i < len; i++) {
		if (!visited[vec[start][i]]) {
			cnt++;
			visited[vec[start][i]] = 1;
			dfs(vec[start][i]);
		}
	}
}

int main()
{
	int n, m, a, b, max=0;
	scanf("%d %d", &n, &m);
	vec.resize(n + 1);
	while (m--) {
		scanf("%d %d", &a, &b);
		vec[b].push_back(a);
		value[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (value[i] == 0)continue;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		dfs(i);
		num[i]=cnt;
		if (max < num[i]) max = num[i];
	}
	for (int i = 1; i <= n; i++) {
		if (max == num[i]) printf("%d ", i);
	}

	return 0;
}