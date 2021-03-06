/*
조건에 st[i]>'z'만 뒀다가 범위를 넘어 앞으로 가는 경우가 생겼다.
그래서 st[i] < 'a' 조건을 추가했다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char st[101];
	scanf("%[^\n]", st);
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] >= 'a') {
			st[i] += 13;
			if (st[i] > 'z' || st[i] < 'a') st[i] -= 26;
		}
		else if (st[i] >= 'A') {
			st[i] += 13;
			if (st[i] > 'Z' || st[i] < 'A') st[i] -= 26;
		}
		printf("%c", st[i]);
	}

	return 0;
}