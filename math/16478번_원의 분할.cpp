/*
ab*cd = ad*bc
*/
#include <cstdio>
using namespace std;

int main()
{
	double ab, bc, cd, da;
	scanf("%lf %lf %lf", &ab, &bc, &cd);
	printf("%lf", ab*cd / bc);

	return 0;
}