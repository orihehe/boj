/*
음수면 음수끼리 절댓값이 큰 순으로 곱한다. 0은 음수가 있다면 곱한다.
양수는 양수끼리 절댓값이 큰 순으로 곱한다. 1의경우 곱하지않고 그냥 더한다.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n,arr[10001],sum=0, minuscnt=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] <= 0)minuscnt++;
	}
	sort(arr, arr + n);
	//음수면 음수끼리 곱, 0이 나온다면 음수랑 곱
	for (int i = 0; i < minuscnt; i++) {
		if (i < minuscnt - 1) {
			sum += abs(arr[i])*abs(arr[i + 1]);
			i++;
		}
		else sum += arr[i];
	}
	for (int i = n-1; i >=minuscnt; i--) {
		if (i > minuscnt) {
			if (arr[i] == 1 || arr[i - 1] == 1) {
				sum += arr[i] + arr[i - 1];
			}
			else {
				sum += arr[i] * arr[i - 1];
			}
			i--;
		}
		else sum += arr[i];
	}
	printf("%d", sum);

	return 0;
}