/*
알바하면서 굉장히 고민하고 이상하게 접근해봤다.
집 와서 갑자기 생각나서 허무했다.
i번째 경우는 i-1번째 경우들 뒤에 1을 붙인것 + i-2번째 경우들 뒤에 00을 붙인것과 같다.
*/

#include <cstdio>
using namespace std;

int arr[1000001];
int main() {
	int n;
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%15746;
	}
	printf("%d", arr[n] % 15746);

	return 0;
}