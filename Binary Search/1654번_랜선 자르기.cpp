/*
처음에 int로 풀었다가 틀렸다. 
계산해보니 cnt에 2^16*1000000까지 들어갈수 있어서 long long으로 바꿨다.
left를 0으로 두고 하니 mid가 0이 되는 경우가 생겨 나누기 부분 런타임에러가 났다. 
0으로 자르는 경우는 생각 안 해도 되니 1로 뒀다.
나무 자르기랑 비슷한 문제..
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	long long k, n, arr[10000], left, right, mid, cnt,nn=0;
	scanf("%lld %lld", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + k);
	left = 1;  // 0으로 뒀다가 틀렸다.
	right = arr[k - 1];
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			nn = mid;
		}
	}
	printf("%lld\n", nn);

	return 0;
}