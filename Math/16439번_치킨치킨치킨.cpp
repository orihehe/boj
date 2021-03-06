/*
chick 배열 맨끝 3곳에 1을 넣어 모든 순열을 구했다.
1인 부분의 치킨 종류를 시킨다고 하였을 때의 선호도를 구해 가장 큰 값을 출력했다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[30][30], chick[30];
int main()
{
	int n, m, i, j, maxsun = 0, person, ps;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	chick[m - 1] = chick[m - 2] = chick[m - 3] = 1;
	do {
		ps = 0;
		for (int j = 0; j < n; j++) {
			person = 0;
			for (int i = 0; i < m; i++) {
				if (chick[i] == 1) {
					person = max(person, arr[j][i]);
				}
			}
			ps += person;
		}
		maxsun = max(maxsun, ps);
	} while (next_permutation(chick, chick + m));
	printf("%d", maxsun);

	return 0;
}