/*
문자열 맨 뒤에서부터 자신보다 작은 문자를 찾아 그 문자의 위치와 자신의 위치를 바꾸고,
찾은 위치 뒤를 오름차순으로 정렬하면 큰수중 가장 작은 수가 나온다.
만약 모두 찾았지만 자신보다 작은 문자가 나오지 않았다면 그 수가 없는 것이다.
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char st[7];
	scanf("%s", st);
	int len = strlen(st);
	for (int i = len - 1; i >= 0; i--) {
		char last = st[i];
		for (int j = i - 1; j >= 0; j--) {
			if (last > st[j]) {
				char tmp = st[j];
				st[j] = st[i];
				st[i] = tmp;
				sort(st + j + 1, st + len);
				printf("%s\n", st);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}
