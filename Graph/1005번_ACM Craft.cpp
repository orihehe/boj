/*
위상정렬 풀이를 보고 풀고나서, 예전에 생각했던 시간초과가 난 코드를 다시 봤다.
메모이제이션을 하지 않아 TLE가 난 코드인 것 같아 다시 짜고 
건설시간이 0인 경우를 빼먹어서 다시 TLE.. 그부분을 고치니 AC를 받았다.

간선의 방향을 거꾸로 넣어 탐색하였다. 
간선을 따라 탐색 후 최댓값+본인 건설 시간을 저장해주었다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int bd[1001];
int time[1001];
vector<vector<int>> vec;
int func(int start) {
	int tmp = 0;
	for (auto v : vec[start]) {
		tmp = max(tmp, time[v]==-1 ? func(v) : time[v]);
	}
	
	time[start] = tmp+bd[start];
	return time[start];
}

int main() {
	int t, n, k, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &bd[i]);
		}
		fill(time, time + n + 1, -1);
		vec.clear();
		vec.resize(n + 1);
		while (k--) {
			scanf("%d %d", &a, &b);
			vec[b].push_back(a);
		}
		scanf("%d", &a);
		func(a);
		printf("%d\n", time[a]);
	}

	return 0;
}