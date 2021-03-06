/*
문제를 풀고 찾아보니 bitset<자릿수> 변수명으로 이진수 입력을 받을 수 있었다.
*/

#include <cstdio>
using namespace std;

int main()
{
	char s1[100001], s2[100001];
	scanf("%s %s", s1, s2);
	for (int i = 0; i < 100000; i++) {
		printf("%d", (s1[i]-'0') & (s2[i]-'0'));
	}
	printf("\n");
	for (int i = 0; i < 100000; i++) {
		printf("%d", (s1[i] - '0') | (s2[i] - '0'));
	}
	printf("\n");
	for (int i = 0; i < 100000; i++) {
		printf("%d", (s1[i] - '0') ^ (s2[i] - '0'));
	}
	printf("\n");
	for (int i = 0; i < 100000; i++) {
		if (s1[i] == '0') printf("1");
		else printf("0");
	}
	printf("\n");
	for (int i = 0; i < 100000; i++) {
		if (s2[i] == '0') printf("1");
		else printf("0");
	}
	printf("\n");
	
	return 0;
}