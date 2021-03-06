#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int visited[20001];
int t, v, e, x, y,dex;
vector<vector<int>> vec;
void dfs(int start,bool b) { // dfs로 true false 번갈아가며 visited에 표기
	for (auto j : vec[start]) {
		int in = j;
		if (visited[in] == 0) {
			b ? visited[in] = 1 : visited[in] = 2;
			dfs(in,!b);
		}
		else if (visited[in] == 1) {
			if (!b) {
				dex = v + 1;
				return;
			}
		}
		else { // 2
			if (b) {
				dex = v + 1;
				return;
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &v, &e);
		vec.clear();
		vec.resize(v+1);
		memset(visited, 0, sizeof(visited));
		while (e--) {
			scanf("%d %d", &x, &y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dex = 1;
		bool bb = true;
		while(dex<=v) { // i
			if (visited[dex] == 0) dfs(dex,bb);  // 사이클 별로 따로
			dex++;
		}
		if (dex == v + 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}