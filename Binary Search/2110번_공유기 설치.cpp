/*
mid의 값의 간격 이상으로 설치했을 때 공유기를 c개만큼 설치할 수 있을까?
위의 방식으로 이분탐색이 가능하다.
왜 이 문제가 이분탐색인지 모르겠어서 질문검색 창을 봤다.ㅠ
*/
#include <cstdio>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int house[200000];
int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &house[i]);
	}
	sort(house, house + n);
	int cnt, left=0, idx, right=MAX, mid, dis;
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1, idx=0; // idx 집위치
		for (int i = 1; i < n; i++) {
			if (house[i] - house[idx] >= mid) {
				cnt++;
				idx = i;
			}
		}
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			dis = mid;
		}
	}
	printf("%d", dis);

	return 0;
}