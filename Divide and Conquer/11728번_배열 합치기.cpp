/*
정렬되어있는 배열인줄 모르고 전체를 sort했다가 다시 풀었다
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int arrA[1000000];
int arrB[1000000];
int ptrA, ptrB;
int main()
{
	int a, b, i;
	scanf("%d %d", &a, &b);
	for (i = 0; i < a; i++) {
		scanf("%d", &arrA[i]);
	}
	for (i = 0; i < b; i++) {
		scanf("%d", &arrB[i]);
	}
	while (ptrA != a && ptrB != b) {
		if (arrA[ptrA] > arrB[ptrB]) {
			printf("%d ", arrB[ptrB++]);
		}
		else printf("%d ", arrA[ptrA++]);
	}
	while (ptrA != a) printf("%d ", arrA[ptrA++]);
	while (ptrB != b)printf("%d ", arrB[ptrB++]);

	return 0;
}