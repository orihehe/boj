/*
여는 괄호가 나오면 재귀로 들어가 값을 구했다.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char sik[101];
int subsum, len;
bool gg = false;
int nextis(int idx, int value) {
	// 뒤에 숫자 있으면 곱함
	if (idx + 1 < len && sik[idx + 1] >= '2' && sik[idx + 1] <= '9') {
		return value * (sik[idx + 1] - '0');
	}
	else {
		return value;
	}
}
int idx;
int func() {
	int tmpsum=0;
	for (;idx < len;) {
		if (sik[idx] == ')') {
			tmpsum = nextis(idx, tmpsum);
			idx++;
			return tmpsum;
		}
		else if (sik[idx] == '(') {
			idx++;
			tmpsum+=func();
		}
		else {
			if (sik[idx] == 'H') {
				tmpsum+=nextis(idx, 1);
			}
			else if (sik[idx] == 'C') {
				tmpsum += nextis(idx, 12);
			}
			else if (sik[idx] == 'O') {
				tmpsum += nextis(idx, 16);
			}
			idx++;
		}
	}
	return tmpsum;
}

int main() {
	scanf("%s", sik);
	len = strlen(sik);
	printf("%d", func());

	return 0;
}