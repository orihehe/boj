/*
첫자리 변환은 맨앞이0이면 0을 출력하면 안 되니 따로 해줬다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char st[333335], tst[4];
	int tmp,len,index=0;
	scanf("%s", &st);
	len = strlen(st);
	tmp = st[0]-'0';
	if (tmp == 0)printf("0");
	while (tmp > 0) {
		tst[index++] = tmp % 2 + '0';
		tmp /= 2;
	}
	for (int i = index - 1; i >= 0; i--)printf("%c", tst[i]);
	for (int i = 1; i < len; i++) {
		switch (st[i])
		{
		case '0': printf("000"); break;
		case '1': printf("001"); break;
		case '2': printf("010"); break;
		case '3': printf("011"); break;
		case '4': printf("100"); break;
		case '5': printf("101"); break;
		case '6': printf("110"); break;
		case '7': printf("111"); break;
		default:
			break;
		}
	}

	return 0;
}