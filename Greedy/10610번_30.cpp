/*
처음엔 문제를 잘못 이해하여 길거리에 찾은 수에 포함된 숫자를 섞어 수를 만드는 것이
모든 숫자를 사용하는 건줄 몰랐다. 고민해봐도 모르겠어서 검색을 해봤더니
30의 배수는 0으로 끝나고, 3으로 나누어 떨어지는 수여야 한다는 특징이 있었다.
또 그것은 각 자릿수의 합이 3으로 나누어 떨어지는 것이라고 한다.
그래서 내림차순정렬 후 조건을 검색하는 식이었다. 이때 모든 수를 쓰는것을 알았다..
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	char st[100001];
	int len,sum=0;
	scanf("%s", st);
	len = strlen(st);
	sort(st, st + len, greater<int>());
	if (st[len - 1] != '0') {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < len; i++) {
		sum += st[i] - '0';
	}
	if (sum % 3 != 0) {
		printf("-1");
	}
	else {
		printf("%s\n", st);
	}

	return 0;
}