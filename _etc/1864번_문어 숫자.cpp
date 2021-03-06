#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char st[9];
	scanf("%s", st);
	while (strcmp(st, "#") != 0) {
		int loc = 1, sum = 0, len = strlen(st);
		for (int i = len - 1; i >= 0; i--) {
			switch (st[i])
			{
			case '-':
				break;
			case '\\':
				sum += loc;
				break;
			case '(':
				sum += loc * 2;
				break;
			case '@':
				sum += loc * 3;
				break;
			case '?':
				sum += loc * 4;
				break;
			case '>':
				sum += loc * 5;
				break;
			case '&':
				sum += loc * 6;
				break;
			case '%':
				sum += loc * 7;
				break;
			case '/':
				sum -= loc;
				break;
			default:
				break;
			}
			loc *= 8;
		}
		printf("%d\n", sum);
		scanf("%s", st);
	}
	return 0;
}