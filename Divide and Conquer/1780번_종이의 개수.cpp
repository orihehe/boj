#include <cstdio>
#include <algorithm>
using namespace std;

int arr[2187][2187];
int cnt[3];  // -1은 cnt[2]에
int i, j;
void paper(int size, int r, int c) {
	int num = arr[r][c], sta=0;
	for (i = r; i < r+size; i++) {
		for (j = c; j < c + size; j++) {
			if (num != arr[i][j]) {
				sta = 1;
				break;
			}
		}
		if (sta) {
			break;
		}
	}
	if (i == r + size && j == c + size) { // 숫자 같음
		if (num == -1) cnt[2]++;
		else cnt[num]++;
	}
	else {
		for (int k = r; k < r + size; k += size / 3) {
			for (int y = c; y < c + size; y += size / 3) {
				paper(size / 3, k, y);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	paper(n, 0, 0);
	printf("%d\n%d\n%d\n", cnt[2], cnt[0], cnt[1]);

	return 0;
}