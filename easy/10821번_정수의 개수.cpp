#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char st[101], cnt = 1;
	scanf("%s", st);
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] == ',') cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}