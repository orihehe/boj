#include <cstdio>
#include <algorithm>
using namespace std;

int sik(int x, int y, char s) {
	switch (s)
	{
	case '+':
		return x + y;
		break;
	case '/':
		return x / y;
		break;
	case '*':
		return x * y;
		break;
	case '-':
		return x - y;
		break;
	default:
		break;
	}
}

int main()
{
	int k1, k2, k3, re1 = 0, re2 = 0;
	char x1, x2;
	scanf("%d %c %d %c %d", &k1, &x1, &k2, &x2, &k3);
	re1 = sik(sik(k1, k2, x1), k3, x2);
	re2 = sik(k1, sik(k2, k3, x2), x1);
	if (re1 > re2) printf("%d\n%d", re2, re1);
	else printf("%d\n%d", re1, re2);

	return 0;
}