/*
이전값들의 합의 최대값과 현재 값을 더했을 때 음수가 되면 최댓값일수 없다.
또한 이전값의 최대가 음수일때 현재값과 더해도 최대일수 없다.
*/
#include <cstdio>
using namespace std;
int arr[100000];
int main()
{
	int n,x,max;
	scanf("%d", &n);
	scanf("%d", &arr[0]);
	max = arr[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i - 1] > 0 && arr[i] + arr[i-1]>0) arr[i] += arr[i - 1];
		if (arr[i] > max)max = arr[i];
	}
	printf("%d\n", max);

	return 0;
}