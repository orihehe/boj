/* 
sosu배열에서 소수를 하나 골라 짝수-소수를 소수인 배열 arr에 확인해본다.
만약 t/2인 소수까지 해봤지만 존재하지 않다면 없는 것이다.
근데 진짜 소수+소수=짝수 성립 하지않는 수가 있는지 여부는 모르겠다.
*/

#include <cstdio>
using namespace std;

int arr[1000001];  // 1000000까지 수들 중 소수여부
int sosu[80000];   // 1000000까지 수중 홀수인 소수 저장
int main()
{
	int m=3, n=1000000, cnt=0,t, no;
	arr[1] = 1;
	for (int i = 2; i <= n/2+1; i++) {
		if (arr[i]) continue;
		for (int j = 2; j*i <= n; j++) {
			if (arr[j*i]==0) 
				arr[j*i]=1;
		}
	}
	for (int i = m; i <= n; i++) {
		if (arr[i] == 0) sosu[cnt++] = i;
	}
	scanf("%d", &t);
	while (t) {
		no = 1;
		for (int i = 0; sosu[i] * 2 <= t; i++) {
			if (arr[t - sosu[i]] == 0) {
				printf("%d = %d + %d\n", t, sosu[i], t - sosu[i]);
				no = 0;
				break;
			}
		}
		if (no) printf("Goldbach's conjecture is wrong.\n");
		scanf("%d", &t);
	}

	return 0;
}