/*
처음엔 배열을 10000000크기로 선언하여 소수인 수를 다 구했다
그리고나서 작은소수부터 나누어 떨어지는 소수를 출력했는데
그냥 포문으로 작은 소수 2부터 나누고 나누면 그 뒤엔 2로 나누어 떨어지는 수로 
자연히 나눌수가 없었다.
*/
#include <cstdio>
using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		while (num > 0) {
			if (num%i == 0) {
				printf("%d\n", i);
			}
			else break;
			num /= i;
		}
	}

	return 0;
}