/*
물이 새는 지점에 L길이 테이프의 앞부분을 맞춰 붙이면 L길이 만큼 뒤는 보지않아도 된다.
앞부분을 맞춰 붙여야 더 많은 범위를 막을 수 있고 그때 테이프 사용 개수가 최소이다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

bool loc[1001];
int main() {
	int n, l, idx = 0, x, cnt=0;
	scanf("%d %d", &n, &l);

	while (n--) {
		scanf("%d", &x);
		loc[x] = true;
	}
	while (idx <= 1000) {
		if (loc[idx]) {
			cnt++;
			idx += l;
		}
		else idx++;
	}
	printf("%d", cnt);

	return 0;
}