#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, m, tmp, paint=2500;
	char board[52][52];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	for (int k = 0; k <= n - 8; k++) {
		for (int l = 0; l <= m - 8; l++) {
			tmp = 0;
			for (int i = k; i < k+8; i++) {
				for (int j = l; j < l+8; j++) {
					if ((i + j + 1) % 2 == 0 && board[i][j] != 'W') {
						tmp++;
					}
					else if ((i + j + 1) % 2 == 1 && board[i][j] != 'B') {
						tmp++;
					}
				}
			}
			paint = min({ paint,tmp, 64 - tmp });
		}
	}
	
	printf("%d", paint);

	return 0;
}