/*
뒷자리에 0이 생기는 경우는 2*5가 있을 경우이다.
따라서 원래 팩토리얼의 2의 개수, 5의 개수를 세고
나눌 팩토리얼 두 개의 2의 개수 5의개수를 빼준 값중 작은 수를 출력하면 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, cnt = 0, cnt2=0, m, x;
	int tmpn, tmpm, tmpx;
	scanf("%d %d", &n, &m);
	x = n - m;
	tmpn = n; tmpm = m; tmpx = x;
	while (n >= 5) {
		cnt += n / 5;
		n /= 5;
	}
	while (tmpn >= 2) {
		cnt2 += tmpn / 2;
		tmpn /= 2;
	}
	while (m >= 5) {
		cnt -= m / 5;
		m /= 5;
	}
	while (x >= 5) {
		cnt -= x / 5;
		x /= 5;
	}
	while (tmpm >= 2) {
		cnt2 -= tmpm / 2;
		tmpm /= 2;
	}
	while (tmpx >= 2) {
		cnt2 -= tmpx / 2;
		tmpx /= 2;
	}
	if (cnt < 0) cnt = 0;
	if (cnt2 < 0) cnt2 = 0;
	printf("%d\n", min(cnt,cnt2));

	return 0;
}