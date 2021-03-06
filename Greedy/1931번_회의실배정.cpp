/*
회의가 끝나는 시간이 빠른것을 선택하는 것이 무조건 회의를 많이 할 수 있다.
따라서 회의가 끝나는 시간을 pair의 first에 입력받아 오름차순 정렬하였다.
*/
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
	int n, endtime=INT_MAX,cnt=1;
	pair<int, int> arr[100000], start, tmp, sidx;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].second, &arr[i].first); // 끝나는 시간을 first에
	}
	sort(arr, arr + n); 
	start = arr[0];
	for (int i = 1; i < n; i++) {
		if (start.first <= arr[i].second) {
			start = arr[i];
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}