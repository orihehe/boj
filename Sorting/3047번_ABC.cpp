#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int arr[3];
	char abc[4];
	scanf("%d %d %d %s", &arr[0], &arr[1], &arr[2], abc);
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++) {
		if (abc[i] == 'A') printf("%d ", arr[0]);
		else if (abc[i] == 'B') printf("%d ", arr[1]);
		else printf("%d ", arr[2]);
	}

	return 0;
}