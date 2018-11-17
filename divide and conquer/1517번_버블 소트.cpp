/*
병합정렬 때 오른쪽 배열 b가 왼쪽 배열 a보다 먼저 들어갈 때 a에 남아있는 원소
수 만큼이 바로 swap횟수이다.
*/
#include <cstdio>
using namespace std;

int tmp[500000], arr[500000];
long long cnt;
void merge_p(int list[], int l, int r, int m) { // 정렬된 것을 합치는 함수
	int a, b, index;
	a = l; b = m + 1; index = l;
	while (a <= m && b <= r) {
		if (list[a] <= list[b])
			tmp[index++] = list[a++];
		else {
			cnt += (long long)m - (long long)a+1;
			tmp[index++] = list[b++];
		}
	}
	while (a <= m) {
		tmp[index++] = list[a++];
	}
	while (b <= r) {
		tmp[index++] = list[b++];
	}
	for (int i = l; i <= r; i++) {
		list[i] = tmp[i];
	}
}

void merge(int list[], int l, int r) { // 두개의 리스트로 나누는 함수
	int mid;
	if (r - l < 1) return;
	mid = (l + r) / 2;

	merge(list, l, mid);
	merge(list, mid + 1, r);
	merge_p(list, l, r, mid);
}

int main()
{
	int n, right, left;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	left = 0;
	right = n - 1;
	merge(arr, left, right);
	printf("%lld", cnt);

	return 0;
}