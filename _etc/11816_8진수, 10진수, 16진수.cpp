/*
strtol(x,NULL,0) 으로 하면 자동으로 변환이 된다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char x[10];
	int len, sum = 0, jin = 1;
	scanf("%s", x);
	len = strlen(x);
	if (x[0] == '0') {
		if (x[1] == 'x') { // 16진수
			for (int i = len-1; i >=2; i--) {
				if (x[i]>'9') sum += (x[i] - 'W')*jin;
				else sum += (x[i] - '0')*jin;
				jin *= 16;
			}
		}
		else { // 8진수
			for (int i = len-1; i >=1; i--) {
				sum += (x[i] - '0')*jin;
				jin *= 8;
			}
		}
		printf("%d\n", sum);
	}
	else { // 10진수
		printf("%s\n", x);
	}

	return 0;
}