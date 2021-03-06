/*
세로가 1일 땐 이동할 수 없다.
세로가 2일 땐 2번 3번 이동방법만 사용할 수 있어 3번까지 이동이 가능하다
세로가 3이상일 땐 3번까지 이동할 땐 가로 4칸까지 간다.
하지만 4번 이동하려 할때 가로6칸까지 4칸, 가로 7칸까지 5칸 이동 가능하다.
가로 8칸부터는 가로-2만큼 이동가능하다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	if (n == 1) {
		printf("1");
	}
	else if (n == 2) {
		m = (m + 1) / 2;
		if (m > 4) printf("4");
		else printf("%d", m);
	}
	else {
		if (m < 7) printf("%d", min(m, 4));
		else printf("%d", m - 2);
	}

	return 0;
}