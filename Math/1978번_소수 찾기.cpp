#include <cstdio>

int num[1000];
int main()
{
	for (int i = 2; i < 1001; i++) {
		for (int j = 2; j < 501; j++) {
			if (i*j > 1000) break;
			num[i*j]++;
		}
	}
	num[1]++;
	int n,x,cnt=0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (num[x] == 0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	return 0;
}