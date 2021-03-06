/*
7명의 난쟁이의 합이 100이 되는 것을 찾았다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int arr[9], c[9] = {0,0,1,1,1,1,1,1,1};
	int sum;
	for (int i = 0; i < 9; i++)scanf("%d", &arr[i]);
	sort(arr, arr + 9);
	do {
		sum = 0;
		for (int i = 0; i < 9; i++) {
			if (c[i] == 1) sum += arr[i];
		}
		if (sum == 100) break;
	} while (next_permutation(c,c+9));
	for (int i = 0; i < 9; i++) {
		if (c[i] == 1) printf("%d\n", arr[i]);
	}

	return 0;
}