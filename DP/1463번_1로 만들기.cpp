/*
arr[n/3],arr[n/2],arr[n-1] 의 경우중 가장 작은 값을 넣어주었다.
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int x, arr[1000001];
void func(int n) {
	int a =1000001, b=1000001, c = 1000001;
	if (n>2 && n % 2 == 0) {
		if (arr[n / 2] == 0) {
			func(n / 2);
		}
		a = arr[n / 2];
	}
	if (n >3 && n % 3 == 0) {
		if (arr[n / 3] == 0) {
			func(n / 3);
		}
		b = arr[n / 3];
	}
	if (n>1 && arr[n - 1] == 0) func(n - 1);
	c = arr[n - 1];
	arr[n] = min(a, min(b,c)) + 1;
}

int main()
{
	scanf("%d", &x);
	arr[2] = 1; arr[3] = 1;
	if(x>3) func(x);
	printf("%d\n", arr[x]);

	return 0;
}