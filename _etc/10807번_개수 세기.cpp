#include <cstdio>
using namespace std;

int n, arr[201], x;
int main(void) {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		arr[x+100]++;
	}
	scanf("%d", &x);
	printf("%d", arr[x+100]);

	return 0;
}