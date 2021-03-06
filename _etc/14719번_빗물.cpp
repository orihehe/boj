/*
첫 높이보다 크거나 같은 높이가 뒤에 있을 경우 첫높이*가로 중앙 높이들 뺀값읖
sum에 넣었다. 그리고 나서 첫높이에 크거나 같은 높이값을 넣어준다. 위치도 기억.
만약 뒤에 크거나 같은 높이가 안 나왔을 경우 뒤에서부터 마지막 빗물 집합 인덱스까지
검사를 한다. 방식은 같다.
*/

#include <cstdio>
using namespace std;

int main()
{
	int h, w, arr[500],first_h, sum=0, index, last_h;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) scanf("%d", &arr[i]);
	first_h = arr[0]; index = 0;
	// 첫 높이보다 큰 높이가 나올 경우
	for (int i = 1; i < w; i++) {
		if (first_h <= arr[i]) { // 집합 끝낼수 있을때
			for (int j = i - 1; j > index; j--) {
				sum += first_h - arr[j];
			}
			first_h = arr[i];
			index = i;
		}
	}
	last_h = arr[w - 1];
	int lindex = w - 1;
	// 위의 경우를 하고 큰 높이가 안 나왔을 경우
	for (int i = w - 2; i >= index; i--) {
		if (arr[i] >= last_h) {
			for (int j = lindex-1; j > i; j--) {
				sum += last_h - arr[j];
			}
			lindex = i;
			last_h = arr[i];
		}
	}
	printf("%d\n", sum);

	return 0;
}
