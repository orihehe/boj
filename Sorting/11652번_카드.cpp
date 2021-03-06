/*
이분탐색 사용해서 풀었지만 굳이 이분탐색을 할 필요가 없을 거 같다.
가장 많이 갖고있는 정수를 구하는 것이므로 어차피 모두.. 확인해야하네..
다른 사람 소스를 보니 sort로 그냥 정렬해도 됐다.. 
*/
#include <cstdio>
#include <algorithm>
using namespace std;

long long tmp[1000000], arr[1000000];
void merge_p(long long list[], long long l, long long r, long long m) {
	long long a, b, index;
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
	for (long long i = l; i <= r; i++) {
		list[i] = tmp[i];
	}
}

void merge(long long list[], long long l, long long r) {
	long long mid;
	if (r - l < 1) return;
	mid = (l + r) / 2;

	merge(list, l, mid);
	merge(list, mid + 1, r);
	merge_p(list, l, r, mid);
}

int main()
{
	long long n, maxnum, maxcnt = 0, i,left,right,minin,maxin,mid;
	pair<long, long> p;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	merge(arr, 0, n - 1);
	for (i = 0; i < n; i++) {
		long long x = arr[i];
		left = 0;
		right = n - 1;
		minin = left - 1; maxin = right + 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] > x) {
				right = mid - 1;
				maxin = mid;
			}
			else {
				left = mid + 1;
			}
		}
		left = 0;
		right = n - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] >= x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
				minin = mid;
			}
		}
		if (maxcnt < maxin - minin - 1) {
			maxcnt = maxin - minin - 1;
			maxnum = x;
			i+= maxin - minin - 2;
		}
	}
	printf("%lld\n", maxnum);

	return 0;
}