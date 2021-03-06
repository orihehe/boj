#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int bx, by, dx, dy, jx, jy, i, bcnt = 0, dcnt = 0;
	scanf("%d %d %d %d %d %d", &bx, &by, &dx, &dy, &jx, &jy);
	dcnt = abs(dx - jx) + abs(dy - jy);
	while (jx != bx && jy != by) {
		if (bx > jx) {
			if (by > jy) {
				by--; bx--; bcnt++;
			}
			else {
				bx--; by++; bcnt++;
			}
		}
		else {
			if (by > jy) {
				by--; bx++; bcnt++;
			}
			else {
				bx++; by++; bcnt++;
			}
		}
	}
	bcnt += abs(bx - jx) + abs(by - jy);
	if (bcnt == dcnt) {
		printf("tie");
	}
	else if (bcnt < dcnt) {
		printf("bessie");
	}
	else {
		printf("daisy");
	}

	return 0;
}