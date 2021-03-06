/*
뒤에서부터 오름차순 쭉 찾는다.
오름차순이 끊길 때의 인덱스를 idx에 저장하고, idx-2까지의 원소는 동일
idx-1의 원소는 원래의 원소보다 큰 원소들중 가장 작은 값을 넣는다.
idx부터 n까지는 작은것부터 차례로 출력한다.

next_permutation 함수를 이용하면 쉽게 구할 수 있다..
*/
#include <cstdio>
#include <algorithm>
using namespace std;

bool check[10001];
int main() {
	int n,idx=0;
	int arr[10001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n; i >= 2; i--) {
		if (arr[i] > arr[i - 1]) {
			idx = i;
			break;
		}
	}
	if (idx == 0) {
		printf("-1");
	}
	else {
		for (int i = 1; i < idx-1; i++) {
			check[arr[i]] = true;
			printf("%d ", arr[i]);
		}
		for (int i = arr[idx-1]+1; i <= n; i++) {
			if (!check[i]) {
				check[i] = true;
				printf("%d ", i);
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				printf("%d ", i);
			}
		}
	}

	return 0;
}