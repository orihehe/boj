#include <cstdio>
#include <cstring>

int main()
{
	char st[1000001];
	bool b = true;
	int cnt = 0;
	scanf("%[^\n]", st);  // 엔터 제외 입력 받기
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (b && st[i] != ' ') {
			cnt++; b = !b;   // 단어의 첫 문자가 나오면 b는 false가 됨
		}
		else if (st[i] == ' ') b = true;
	}
	printf("%d\n", cnt);

	return 0;
}