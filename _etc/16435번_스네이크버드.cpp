/*
과일들 높이가 들은 배열을 정렬한 후
과일을 먹었을 때 키를 늘려주고, 만약 키보다 높은 곳에 과일이 있으면 멈추고 
출력을 하였다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, l, arr[1000], i;
	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (i = 0; i < n; i++) {
		if (arr[i] <= l) {
			l++;
		}
		else break;
	}
	printf("%d", l);

	return 0;
}