/*
bfs를 통해 각 노드의 레벨을 구했다.
그 다음, 노드의 부모는 본인 레벨 -1 이므로 본인과 연결된 노드들중 본인레벨 -1 인것을 찾아 출력했다.
*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int level[100001], lev = 2, s;
int main(void) {
	int n, a,b,nn;
	vector<vector<int>> vec;
	queue<int> q;

	scanf("%d", &n);
	vec.resize(n+1);
	level[1] = 1;
	nn = n-1;
	while (nn--) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < vec[1].size(); i++) { // 1(root)과 연결된 노드들 q에 푸쉬
		q.push(vec[1][i]);
	}
	s = q.size();
	while (!q.empty()) {
		if (s <= 0) { // s만큼 q를 pop했다면 다음 레벨 시작
			s = q.size();
			lev++;
		}
		int tmp = q.front();
		q.pop();
		level[tmp] = lev;
		for (int i = 0; i < vec[tmp].size(); i++) {
			if (level[vec[tmp][i]] >= 1) continue;
			q.push(vec[tmp][i]);
		}
		s--;
	}
	for (int i = 2; i <= n; i++) {
		s = vec[i].size();
		int now = level[i];
		for (int j = 0; j < s; j++) {
			if (level[vec[i][j]] == now - 1) {
				printf("%d\n", vec[i][j]);
				break;
			}
		}
	}

	return 0;
}