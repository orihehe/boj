/*
커서의 왼쪽은 f배열에, 오른쪽은 b배열에 저장했다.
입력부분에서 조금 헤맸는데 \n이 버퍼에 있어 입력이 안 받아진거 같았다.
P의 경우 띄어쓰기 포함해서 받아야 함으로 %[^\n]를 사용했다. 그래서 getchar()가
필요했던 거 같다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

char f[600000], b[600000], input[4], tmp;
int main()
{
	int bptr = 0, len, n;
	scanf("%s %d", f, &n);
	getchar();
	len = strlen(f);
	while (n--) {
		scanf("%[^\n]s", input);
		switch (input[0])
		{
		case 'L':
			if (bptr < len) {
				b[bptr] = f[len - 1 - bptr];
				bptr++;
			}
			break;
		case 'D':
			if (bptr > 0) {
				f[len - 1 - bptr] = b[--bptr];
			}
			break;
		case 'B':
			if (len-bptr >= 1) {
				len--;
			}
			break;
		case 'P':
			tmp = input[2];
			f[++len - 1 - bptr] = tmp;
			break;
		default:
			break;
		}
		getchar();
	}
	for (int i = 0; i <= len - 1 - bptr; i++) printf("%c", f[i]);
	for (int i = bptr - 1; i >= 0; i--) printf("%c", b[i]);

	return 0;
}