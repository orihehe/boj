#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, arr[30][30];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[0][i] = 1;
		arr[i][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	cout << arr[n - 1 - (m - 1)][m - 1] << "\n";

	return 0;
}