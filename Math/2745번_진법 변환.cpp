#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char st[33];
	int n,len, sum=0,jin=1;
	scanf("%s %d", st, &n);
	len = strlen(st);
	for (int i = len - 1; i >= 0; i--) {
		if (st[i] >= 'A') sum += (st[i] - 55)*jin;
		else sum += (st[i] - '0')*jin;
		jin *= n;
	}
	printf("%d\n", sum);

	return 0;
}