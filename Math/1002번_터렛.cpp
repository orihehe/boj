/*
내접,외접 문제다.
참고 : https://mathbang.net/101
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct turret {
	double x, y, r;
};

int p_cnt(turret a, turret b) {  // a반지름이 더 큼
	if (a.x == b.x && a.y == b.y) {  // 좌표 같을 때
		if (a.r == b.r) {
			return -1;
		}
		else {
			return 0;
		}
	}
	double distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	if (a.r + b.r == distance || a.r - b.r == distance) {
		return 1;
	}
	else if (a.r - b.r<distance && a.r + b.r>distance) {
		return 2;
	}
	else {
		return 0;
	}
}

int main()
{
	turret t1, t2;
	int cnt,t;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf %lf %lf %lf %lf %lf", &t1.x, &t1.y, &t1.r,
			&t2.x, &t2.y, &t2.r);

		if (t2.r > t1.r) {
			cnt = p_cnt(t2, t1);
		}
		else cnt = p_cnt(t1, t2);
		printf("%d\n", cnt);
	}

	return 0;
}