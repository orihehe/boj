/*
days배열에 days[i][j]를 첫 지점으로 선택했을 경우의 최대값을 저장해둔다.
howlong함수에서 i,j위치의 상,하,좌,우와 대나무 수를 비교하여 최대값을 찾는다.
days배열에 값이 없다면 아직 howlong함수를 거치지 않은 것으로
howlong함수를 호출해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[500][500], days[500][500];
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
int howlong(int x, int y) {
	int a, x1,y1;
	for (int i = 0; i < 4; i++) {
		x1 = x + xx[i]; 
		y1 = y + yy[i];
		if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) {
			continue;
		}
		if (arr[x1][y1] > arr[x][y]) {
			if (days[x1][y1]) a = days[x1][y1];
			else a = howlong(x1, y1);
			days[x][y] = max(a + 1, days[x][y]);
		}
	}
	return days[x][y];
}

int main()
{
	int max1 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!days[i][j]) howlong(i, j);
			max1 = max(max1,days[i][j]);
		}
	}
	printf("%d\n", max1+1);

	return 0;
}