#include <cstdio>
using namespace std;

char st[6561][6561];
void star(int r, int c, int size) {
	if (size == 1) {
		st[r][c] = '*';
		return;
	}
	for (int i = r; i < r + size; i+=size/3) {
		for (int j = c; j < c + size; j+=size/3) {
			if (i == r + size / 3 && j == c + size / 3) continue;
			star(i, j, size / 3);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	star(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (st[i][j] == '*') printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}