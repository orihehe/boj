#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct union_find {
	vector<int> parent;
	vector<int> height;

	void init(int size) {
		parent.clear(); height.clear();
		for (int i = 0; i <= size; i++) {
			parent.push_back(i); // 자기자신 루트
			height.push_back(0); // 트리높이
		}
	}
	int find_root(int v) {
		if (parent[v] == v) return v;
		return parent[v] = find_root(parent[v]);
	}
	bool same_tree(int v1, int v2) {
		return find_root(v1) == find_root(v2);
	}
	void merge(int v1, int v2) {
		v1 = find_root(v1), v2 = find_root(v2);
		if (v1 == v2) return; // 같은 집합
		if (height[v1] < height[v2]) swap(v1, v2); // 높이가 더 큰 트리를 v1로
		parent[v2] = v1;
		if (height[v1] == height[v2]) height[v1]++;
	}

}uf;

int main() {
	int n, m, cm,a,b;
	scanf("%d %d", &n, &m);
	uf.init(n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &cm, &a, &b);
		if (cm) {
			printf("%s\n", uf.same_tree(a, b) ? "YES" : "NO");
		}
		else {
			uf.merge(a, b);
		}
	}

	return 0;
}