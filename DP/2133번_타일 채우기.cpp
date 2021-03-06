/*
처음 점화식을 세웠을 땐
N(2)=3 / N(4)=N(2)*N(2)+E4 / N(6)=N(4)*N(2)+E6   //Ex는 각 N(x)에서 새로 생기는 타일 배치
이런 식으로 해서 N(x)=N(x-2)*N(2)+2 이렇게 세웠었다.
N(6)=(N(2)^2+E4)N(2)+E6 -> N(6)=N(2)^3+N(2)*E4+E6 
이렇게 해야했다. 다른 변수인 샘인데 그냥 계산해서 넣어서 처음에 틀렸다.
*/

#include <cstdio>
using namespace std;

int main()
{
	int arr[31],n;
	scanf("%d", &n);
	if (n % 2 == 1) {
		printf("0\n");
		return 0;
	}
	arr[0] = 1;
	arr[2] = 3;
	for (int i = 4; i <= n; i+=2) {
		arr[i] = arr[i - 2] * arr[2];
		for (int j = 4; j <= i; j += 2) {
			arr[i] += arr[i - j] * 2;
		}
	}
	printf("%d\n", arr[n]);

	return 0;
}