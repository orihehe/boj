/*
longer배열에 앞에서부터 오름차수 가장 긴 수열 카운트
lower배열에 뒤에서부터 오름차수 가장 긴 수열 카운트
i기준 앞뒤 카운트한것 최댓값 찾아 출력
*/
#include <cstdio>
using namespace std;

int n, arr[1000], longer[1000], lower[1000], max;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	longer[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >=0; j--) {
			if (arr[j] < arr[i] && longer[j] >= longer[i]) {
				longer[i] = longer[j];
			}
		}
		longer[i]++;
	}
	lower[n - 1] = 1;
	for (int i = n-2; i >= 0; i--) {
		for (int j = i +1; j < n; j++) {
			if (arr[j] < arr[i] && lower[j] >= lower[i]) {
				lower[i] = lower[j];
			}
		}
		lower[i]++;
	}
	for (int i = 0; i < n; i++) {
		if (max < longer[i]+lower[i]-1) max = longer[i] + lower[i]-1;
	}
	printf("%d\n", max);

	return 0;
}