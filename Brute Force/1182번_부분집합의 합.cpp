/*
완전탐색 문제이다.
정렬을 하게 되면 뒤에 나온 수들을 더하기 전 이미 s보다 같거나 커졌다면 뒤의 경우를
보지 않아도 된다. -가지치기(prunning)
따라서 현재 위치의 수를 더했을 때 s보다 크고, 현재 수가 양수라면 뒤의 경우를
보지 않는다. 음수라면 뒤에 음수가 나와 s를 만들수 있으므로 진행한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, s, arr[20],cnt;
void dfs(int idx, int sum) {
	if (idx >= n) {
		return;
	}
	if (sum + arr[idx] > s) {
		if(arr[idx]>=0)
			return;
	}
	if (sum + arr[idx] == s) cnt++;

	dfs(idx + 1, sum + arr[idx]);
	dfs(idx + 1, sum);
}

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	dfs(0, 0);
	printf("%d", cnt);

	return 0;
}