/*
세그먼트 트리 (segment tree)
부모노드는 자식 노드들의 합
배열의 범위 (start~end)의 합을 노드에 저장하고 범위를 반 나눠
자식노드 왼쪽: arr배열 범위 (start~(start+end)/2) 의 합
자식노드 오른쪽: arr배열 범위 ((start+end)/2+1~end)의 합을 저장한다.
리프노드는 arr배열의 값이 들어간다. 범위가 1~1 , 2~2 ... 이기 때문

값을 바꾸는 데에 시간복잡도 - O(logN)
구간 합 구하는 데에 시간복잡도 - O(logN)
*/
#include <cstdio>
#include <cmath>
using namespace std;

long long arr[1000001];
long long *tree;
long long make_tree(int idx,int start, int end) {
	if (start == end)   // 리프노드는 arr배열 각 요소
		tree[idx] = arr[start];
	else {  // start~end구간의 합
		tree[idx] = make_tree(idx * 2, start, (start + end) / 2) +
			make_tree(idx * 2 + 1, (start + end) / 2 + 1, end);
	}
	return tree[idx];
}
void change_value(int idx, int start, int end, int a, long long cha) {
	if (a<start || a>end) // 범위 밖이라면
		return;
	tree[idx] = tree[idx] + cha;
	if (start != end) {  // 리프노드가 아니라면
		change_value(idx * 2, start, (start+end)/2, a, cha);
		change_value(idx * 2+1, (start + end) / 2+1, end, a, cha);
	}
}
long long find_sum(int idx, int start, int end, int left, int right) {
	if (left > end || right < start) // 찾는 범위가 겹치지 않을 때
		return 0;
	if (start >= left && end <= right)  // 찾는 범위가 idx의 구간을 포함할 때
		return tree[idx];
	return find_sum(idx * 2, start, (start + end) / 2, left, right) +
		find_sum(idx * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	int n, m, k, a, l, r;
	long long sum;
	scanf("%d %d %d", &n, &m, &k);
	int h = ceil(log2(n));
	tree = new long long[(1 << (h + 1)) - 1]; // 2^(h+1)-1
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	make_tree(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a, &l, &r);
		if (a == 1) {
			change_value(1, 1, n, l, r - arr[l]);
			arr[l] = r;
		}
		else if (a == 2) {
			sum = find_sum(1, 1, n, l, r);
			printf("%lld\n", sum);
		}
	}
	delete[] tree;

	return 0;
}
