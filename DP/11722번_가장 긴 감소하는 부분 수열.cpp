/*
본인보다 큰 arr[0][j]들 중 가장 긴 값 arr[1][j]를 arr[1][i]에 넣고 +1(본인)
*/
#include <cstdio>
using namespace std;

int arr[2][1000], n, mxcnt; // arr[1]엔 카운트
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
	}
	arr[1][0]++;
	for (int i = 1; i < n; i++) {
		mxcnt = 0;
		for (int j = i-1; j >= 0; j--) {
			if (arr[0][j] > arr[0][i] && mxcnt<arr[1][j]) {
				mxcnt = arr[1][j];
			}
		}
		arr[1][i] = mxcnt + 1;
	}
	mxcnt = 0;
	for (int i = 0; i < n; i++) {
		if (mxcnt < arr[1][i]) mxcnt = arr[1][i];
	}
	printf("%d\n", mxcnt);

	return 0;
}