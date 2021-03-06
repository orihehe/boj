#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
	int t,x1,x2,y1,y2, n, x3,y3,cnt;
	double dist1, dist2,r;
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d %lf", &x3, &y3, &r);
			dist1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
			dist2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
			if (dist1 < r && dist2 > r) {
				cnt++;
			}
			else if (dist2<r && dist1>r) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
