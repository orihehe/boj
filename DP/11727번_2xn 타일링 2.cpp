/*
for (int i = 3; i <= n; i++) {
	if (i % 2 == 0) {
		arr[i] = (arr[i - 1] / 2 + arr[i - 2] * arr[2])%mod;
	}
	else {
		arr[i] = (arr[i - 1] * 2 - 1)%mod;
	}
}
처음 점화식을 위에 처럼 만들었다.
식은 맞는 거 같지만 mod를 하면 값이 맞지 않는다.
물어보니 mod를 하려면 곱셈, 덧셈만 있어야 한다고 한다.
생각해보니 나누면 값이 바뀌는거 같다..
나머지 값이 배열에 저장이 되어있는데 나눴을 때 맨 앞에서 값을 빌려올 수가 없다.
빼기의 경우도 마찬가지...
테스트 케이스에서는 값이 똑같이 나와서 전혀 눈치 못 챘는데
다른분 점화식과 내 점화식 출력을 쭉 해보니 중간에 값이 바꼇다.
운좋게 앞에선 걸리지 않았던 거였다..
*/

#include <cstdio>
#define mod 10007
using namespace std;

int main()
{
	int n,arr[1001];
	scanf("%d", &n);
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % mod;
	}
	
	printf("%d\n", arr[n]);

	return 0;
}