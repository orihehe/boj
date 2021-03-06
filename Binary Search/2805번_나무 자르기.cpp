/*
초기 left=0 right=나무 최고 높이
이분 탐색을 사용하여 자르려는 높이를 mid=(left+right)/2로 설정하여
arr-mid값을 sum(자른 후 가져갈수 있는 나무 높이)에 저장.
sum>=m일때 high에 mid값을 저장해주면 마지막 high값으로 잘랐을 때
가져갈 수 있는 나무가 같거나 크게된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[1000000];
int main()
{
	long long n, m,left,right,mid,sum = 0,high=0;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	left = 0;
	right = arr[n-1];
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] - mid > 0) sum += arr[i] - mid;
		}
		if (sum < m) right = mid - 1;
		else {
			left = mid + 1;
			high = mid;
		}
	}
	printf("%lld\n", high);

	return 0;
}