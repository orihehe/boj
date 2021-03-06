/*
프림 알고리즘으로 풀려다가 연결되어있는 정점들 집합끼리 잇는 방법은 크루스칼 알고리즘이
나은 것 같아 바꿨다. 유니온 파인드는 아직 공부를 안 해서 검색해서 가져왔다. 
내일 일어나서 공부해봐야겠다..

크루스칼 알고리즘 - 
출처: http://weeklyps.com/entry/크루스칼-알고리즘-Kruskals-algorithm [weekly ps]
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 2000000000001
#define ll long long
#define P pair<ll,ll>
using namespace std;

int n, m, cnt;
P arr[1001];
struct union_find_tree {
	vector<int> parent;
	vector<int> height;
	vector<int> group_size;

	void init(int uf_n) {
		parent.clear(), height.clear();
		group_size.clear();
		for (int i = 0; i<uf_n; i++) {
			parent.push_back(i);
			height.push_back(0);
			group_size.push_back(1);
		}
	}

	int get_root(int now) {
		if (parent[now] == now) return now;
		return parent[now] = get_root(parent[now]);
	}

	bool same_set(int v1, int v2) {
		return get_root(v1) == get_root(v2);
	}

	void merge(int v1, int v2) {
		v1 = get_root(v1), v2 = get_root(v2);
		if (v1 == v2) return;
		if (height[v1] < height[v2]) swap(v1, v2);
		parent[v2] = v1;
		group_size[v1] += group_size[v2];
		if (height[v1] == height[v2])
			height[v1]++;
	}
}uf;

struct edge {
	int v1, v2;
	ll cost;
	bool operator < (const edge& e1) const { return cost < e1.cost; }
};
vector<edge> e;

ll myPow(P o, P r) {
	ll tmp1 = o.first - r.first;
	ll tmp2 = o.second - r.second;
	return tmp1 * tmp1 + tmp2 * tmp2;
}

double kruskal() {
	sort(e.begin(), e.end());
	double ret=0;
	for (edge &v : e) {
		if (!uf.same_set(v.v1, v.v2)) { // 두 정점이 끊어져 있는가?
			ret += sqrt(v.cost);       // 가중치를 ret에 더함
			uf.merge(v.v1, v.v2); // 두 정점 연결
		}
	}
	return ret;
}

int main() {
	ll a, b;
	int aa, bb;
	scanf("%d %d", &n, &m);
	//좌표 입력
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &a, &b);
		arr[i] = { a,b };
	}
	// 간선
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			e.push_back({ i,j,myPow(arr[i],arr[j]) });
		}
	}
	uf.init(n + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &aa, &bb);
		uf.merge(aa, bb);
	}
	printf("%.2lf", kruskal());

	return 0;
}