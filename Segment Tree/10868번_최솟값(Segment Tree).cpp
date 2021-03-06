/*
a~b번째 정수에서의 최솟값을 찾는 문제이므로 세그먼트 트리 사용
구간의 최솟값을 노드에 저장했다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAX 1000000001
using namespace std;

long long arr[100001];
long long *tree;
long long make_tree(int idx,int start, int end) {
	if (start == end)   // 리프노드는 arr배열 각 요소
		tree[idx] = arr[start];
	else {  // start~end 구간의 최솟값
		tree[idx] = min(make_tree(idx * 2, start, (start + end) / 2),
			make_tree(idx * 2 + 1, (start + end) / 2 + 1, end));
	}
	return tree[idx];
}
long long find_sum(int idx, int start, int end, int left, int right) {
	if (left > end || right < start) // 찾는 범위가 겹치지 않을 때
		return MAX;
	if (start >= left && end <= right)  // 찾는 범위가 idx의 구간을 포함할 때
		return tree[idx];
	return min(find_sum(idx * 2, start, (start + end) / 2, left, right),
		find_sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	int n, m, l, r;
	long long sum;
	scanf("%d %d", &n, &m);
	int h = ceil(log2(n));
	int treeSize = (1 << (h + 1)) - 1;
	tree = new long long[treeSize]; // 2^(h+1)-1
	fill(tree, tree + treeSize, MAX);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	make_tree(1, 1, n);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l, &r);
		sum = find_sum(1, 1, n, l, r);
		printf("%lld\n", sum);
	}
	delete[] tree;

	return 0;
}
