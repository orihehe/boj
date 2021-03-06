/*
병합정렬을 써보았다.
처음에 main안에arr배열을 선언했는데 스택 오버플로우가 났다. 
전역 변수로 선언하니 잘 되었는데 전역변수는 힙 공간에 잡혀서 그렇다고 한다.
그래서 merge 함수들의 매개변수 list가 필요없게 되었지만.. 
고치기 귀찮아 그냥 뒀다..
*/

#include <cstdio>
using namespace std;

int tmp[1000000], arr[1000000];
void merge_p(int list[], int l, int r, int m) { // 정렬된 것을 합치는 함수
	int a, b, index;
	a = l; b = m + 1; index = l;
	while (a <= m && b <= r) {
		if (list[a] < list[b])
			tmp[index++] = list[a++];
		else tmp[index++] = list[b++];
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
	merge(list,mid + 1, r);
	merge_p(list, l,r,mid);
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
	merge(arr,left,right);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;
}