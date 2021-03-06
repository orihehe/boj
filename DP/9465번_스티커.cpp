/*
N[i][j]=max(N[(i+1)%2][j-1],N[(i+1)%2][j-2])+arr[i][j]
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, t, arr[2][100000], maxsco[2][100000];
int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
				maxsco[i][j] = 0;
			}
		}
		maxsco[0][0] = arr[0][0];
		maxsco[1][0] = arr[1][0];
		if (n > 1) {
			maxsco[0][1] = arr[1][0] + arr[0][1];
			maxsco[1][1] = arr[1][1] + arr[0][0];
		}
		if (n > 2) {
			maxsco[0][2] = arr[0][2] + max(maxsco[1][1], maxsco[1][0]);
			maxsco[1][2] = arr[1][2] + max(maxsco[0][1], maxsco[0][0]);
		}
		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				maxsco[i][j] = arr[i][j] + max(maxsco[(i + 1) % 2][j - 1], maxsco[(i + 1) % 2][j - 2]);
			}
		}
		printf("%d\n", max(maxsco[0][n - 1], maxsco[1][n - 1]));
	}

	return 0;
}