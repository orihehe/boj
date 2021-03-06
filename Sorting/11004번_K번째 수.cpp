/*
nth_element 함수를 사용하면 정렬 후 n번째 수를 찾을 수 있다.
모든 수를 정렬하는 것이 아니라 n번째 수 이전엔 n보다 작거나 같은수를,
n번째 수 이후엔 n보다 크거나 같은수를 배치해 구한다고 한다.
quick selection 알고리즘을 나중에 구현해봐야겠다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[5000000];
int main() 
{
	int n,k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	nth_element(arr, arr + k-1, arr + n);
	printf("%d\n", arr[k - 1]);

	return 0;
}