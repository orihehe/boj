// 각 경우 세보다가 규칙을 찾았다.. 다른 사람 풀이를 봐야겠다.

#include <cstdio>
using namespace std;

int main()
{
	int n, m,t,arr[31][31];
	scanf("%d", &t);
	for (int i = 0; i <= 30; i++) { 
		arr[0][i] = 1; 
		arr[i][0] = 1; 
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	while (t--) {
		scanf("%d %d", &n, &m);
		printf("%d\n", arr[n][m-n]);
	}

	return 0;
}