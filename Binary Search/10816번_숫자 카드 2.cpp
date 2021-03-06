/*
이분탐색을 두 번 하여 구했다.
minin에는 x값이 처음 나오는 인덱스-1이 저장되고 
maxin에는 x값의 마지막 인덱스 +1이 저장된다.
따라서 maxin-minin-1을 출력하였다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[500000];
int main()
{
	int n, m,x,left,right,mid,minin,maxin;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &x);
		left = 0;
		right = n - 1;
		minin = left-1; maxin = right+1;
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
		printf("%d ", maxin-minin-1);
	}

	return 0;
}