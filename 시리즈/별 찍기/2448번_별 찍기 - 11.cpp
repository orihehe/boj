/*
메인에서 포문을 j=0부터 했더니 맨앞에 공백이 출력되어 계속 틀렸었다. 
*/
#include <cstdio>
using namespace std;

char star[6145][6145];
void draw(int r, int c, int size) {
	if (size == 1) return;
	draw(r, c, size / 2);
	draw(r + size / 2, c - size / 2, size / 2);
	draw(r + size / 2, c + size / 2, size / 2);
	star[r][c] = '*';
	star[r + 1][c - 1] = '*';
	star[r + 1][c + 1] = '*';
	for (int i = c - 2; i <= c + 2; i++) star[r + 2][i] = '*';
}

int main()
{
	int n;
	scanf("%d", &n);
	draw(0, n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n * 2; j++) {
			if (star[i][j] == '*') printf("*");
			else printf(" ");
		}
		printf("\n");
	}

	return 0;
}