// a와b는 서로소이므로 그냥 하면 된다

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d %d", b - a, b);

	return 0;
}