#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

char map[1024][1024];
void star(int r, int c, int size) {
	if (size == 1)return;
	star(r, c, size / 2);
	star(r, c + size / 2, size / 2);
	star(r + size / 2, c, size / 2);
	map[r][c] = '*';
	map[r + 1][c] = '*';
	map[r][c + 1] = '*';
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("*"); return 0;
	}
	star(0, 0, pow(2, n));
	for (int i = 0; i < pow(2, n); i++) {
		for (int j = 0; j <pow(2, n) - i; j++) {
			if (map[i][j] == '*')printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}