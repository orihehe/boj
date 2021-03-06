/*
arr[x][y] 에서 x는 자리수 y는 1의자리수 이다.
두 자리수의 1의자리수가 5인 수의 경우는 5앞에 1의자리가 4,6인 x-1자리수의 경우의수 합이 된다.
1의자리수가 9인 경우 앞에 8만 올수있고, 0인경우 앞에 1만 올 수 있으므로 따로 구해준다.
처음에 sum을 구할때 sum+=arr[n][i]%na로 해서 계속 틀렸었다.
저런식으로 한다면 sum이 오버플로가 났을겄이다
*/
#include <cstdio>
#define na 1000000000
using namespace std;

int main()
{
	int n,arr[101][10],sum=0;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) arr[1][i] = 1;
	arr[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][j + 1]%na;
			else if (j == 9) arr[i][j] = arr[i - 1][j - 1]%na;
			else arr[i][j] = (arr[i - 1][j + 1] % na + arr[i - 1][j - 1] % na)% na;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum = (sum+arr[n][i])%na;
	}
	printf("%d\n", sum%na);

	return 0;
}