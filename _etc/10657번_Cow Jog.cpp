/*
트랙 길이가 무한대이므로 앞에 있는 소가 느리면 만날수밖에 없다.
처음에 소가 한칸을 차지한다고 생각해서 칸을 채우며 연속하면 그룹으로 따졌는데
앞에 달리는 소와 속도가 같으면 절대 그룹이 될 수 없는 것이었다.
어렵게 생각해서 풀다가 다시 생각해보니 쉬운 문제였다.
*/
#include <cstdio>
using namespace std;

int arr[100000];
int main() {
	int n, group, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d",&x, &arr[i]);
	}
	group = 1;
	int head = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (head >= arr[i]) { // 뒤에 애보다 빠르거나 같다면
			head = arr[i];
			group++;
		}
	}
	printf("%d", group);

	return 0;
}