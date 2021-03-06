/*
i위치의 포도주를 마신다고 했을 때의 최대값을 저장한다.
i>6 일때
i의 포도주 + i-1의 포도주 + i-4의 최대값 -> 두칸을 띄어 마실수 있으므로
i의 포도주 + i-1의 포도주 + i-3의 최대값
i의 포도주 + i-2의 최대값
세 가지 경우의 최대값을 저장한다.
모두 저장한 후 맨 뒤의 두 최대값중 큰 것을 출력한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, arr[10001], max1[10001], m=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	max1[1] = arr[1];
	if(n>1)
		max1[2] = arr[1] + arr[2];
	if(n>2)
		max1[3] = arr[3] + max(arr[1], arr[2]);
	for (int i = 4; i <= n; i++) {
		max1[i] = max(arr[i - 1] + max1[i - 3], max1[i - 2]) + arr[i];
		if (i > 5) {
			max1[i] = max(max1[i - 4] + arr[i - 1] + arr[i], max1[i]);
		}
	}
	m = max(max1[n], max1[n - 1]);
	printf("%d\n", m);

	return 0;
}