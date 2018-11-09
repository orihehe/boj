#include <cstdio>
using namespace std;

int main()
{
	char st[33];
	int n, origin, index=0;
	scanf("%d %d", &origin, &n);
	while (origin > 0) {
		if (origin%n >= 10) {
			st[index++] = origin % n + 55;
		}
		else {
			st[index++] = origin % n + '0';
		}
		origin /= n;
	}

	for (int i = index-1; i >= 0; i--) printf("%c", st[i]);

	return 0;
}