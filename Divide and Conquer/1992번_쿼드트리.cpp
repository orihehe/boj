#include <cstdio>
using namespace std;

char image[65][65];
bool same(int r, int c, int size) {
	char tmp = image[r][c];
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (tmp != image[i][j])
				return false;
		}
	}
	return true;
}

void q_tree(int r,int c,int size) {
	if (same(r, c, size)) {
		printf("%c", image[r][c]);
	}
	else {
		printf("(");
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				q_tree(r + i * size / 2, c + j * size / 2, size / 2);
			}
		}
		printf(")");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", image[i]);
	}
	q_tree(0, 0, n);

	return 0;
}