#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,i, len,sta;
	char st[51][51], tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", st[i]);
	}
	len = strlen(st[0]);
	for (i = 0; i < len; i++) {
		tmp = st[0][i];
		sta = 0;
		for (int j = 1; j < n; j++) {
			if (st[j][i] != tmp) {
				printf("?");
				sta = 1;
				break;
			}
		}
		if(!sta) printf("%c", tmp);
	}

	return 0;
}