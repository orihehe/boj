/*
0~999900채널을 숫자버튼으로 누른다고 가정, 각 자릿수에 고장난 버튼이 있다면
그 채널을 숫자버튼으로 가지 못하므로 넘어간다.
채널이 500000까지 있지만 999900채널 까지 고려하는 이유는 채널은 무한대이고
500000채널을 가려는데 9와 0외의 숫자 버튼이 고장났다고 하면, 999900에서 내려갈 수도
있다. 하지만 100에서 + 버튼으로 올라가는 게 더 조금 누르게 된다. 그래서 최대 999900으로 뒀다.
*/


#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

bool broken[10];
int main() {
	int n, m, x, now=100, minPress;
	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d", &x);
		broken[x] = true;
	}
	if (m == now) {  // 현재 채널과 같으니 누를 필요 없음
		printf("0");
		return 0;
	}
	minPress = abs(n - now);  // 숫자 안 누르고 +,-만 조작
	for (int i = 0; i <= 999900; i++) {
		if (i == 0) {
			if (broken[0]) {
				continue;
			}
			minPress = min(minPress, 1 + abs(n-i));
			continue;
		}
		int numcnt=0, tmp=i;
		while (tmp > 0) {
			if (broken[tmp % 10]) {
				break;
			}
			numcnt++;
			tmp /= 10;
		}
		if (tmp == 0) { // 이 채널 갈수있음
			minPress = min(minPress, numcnt + abs(n-i));
		}
	}
	printf("%d", minPress);

	return 0;
}