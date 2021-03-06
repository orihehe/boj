/*
먼저 배열을 제곱수 1로만 구성했을때의 수로 채운다.
다음으로 2의 제곱수~i보다 작은 제곱수중 가장 큰 제곱수 각각을 넣었을 시
가장 작은 값을 배열에 넣어준다. 이전 값들에 최솟값이 들어있기 때문에
가장 작은 조합을 찾을 수 있다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j*j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}
	printf("%d\n", arr[n]);

	return 0;
}