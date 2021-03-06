#include <iostream>
#include <string>
using namespace std;

void func(int n, int start, int end, int mid) {
	if (n == 1) {
		printf("%d %d\n", start, end);
		return;
	}
	func(n - 1, start, mid, end);
	printf("%d %d\n", start, end);
	func(n - 1, mid, end, start);
}

int main() {
	int k, tmp, up = 0;
	string su = "1";

	scanf("%d", &k);
	for (int i = 1; i < k; i++) {
		int len = su.length();
		for (int j = len - 1; j >= 0; j--) {
			tmp = su[j] - '0';
			if (tmp >= 5) {
				su[j] = tmp * 2 - 10 + up + '0';
				up = 1;
			}
			else {
				su[j] = tmp * 2 + up + '0';
				up = 0;
			}
		}
		if (up == 1)
			su = "1" + su;
		su[len - 1 + up] += 1;
		up = 0;
	}

	printf("%s\n", su.c_str());
	func(k, 1, 3, 2);

	return 0;
}