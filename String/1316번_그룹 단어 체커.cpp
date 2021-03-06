#include <cstdio>
#include <cstring>

int num[27];
int main()
{
	int n = 0, len, cnt = 0;
	char st[101], lastC;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", st);
		lastC = st[0];
		memset(num, 0, sizeof(num));
		num[lastC - 'a']++;
		len = strlen(st);
		for (int i = 1; i < len; i++) {
			if (st[i] != lastC) { // 이전 문자랑 다르면
				lastC = st[i];
				if (num[lastC - 'a'] > 0) { // 현재 문자가 전에 나왔었다면
					cnt--;
					break;
				}
				num[lastC - 'a']++;
			}
		}
		cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}