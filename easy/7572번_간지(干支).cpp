#include <cstdio>
using namespace std;

int main()
{
	char st12[13] = "IJKLABCDEFGH";
	char st10[11] = "6789012345";
	int year;
	scanf("%d", &year);
	printf("%c%c\n", st12[year % 12], st10[year % 10]);

	return 0;
}