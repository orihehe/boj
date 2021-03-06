/*
처음에 int로 선언하여 풀었는데
arr[i]+arr[i-1] 부분이 int범위를 넘어버려 틀렸다.
도착직전 이동거리가 1광년이어야 하므로 x와 y의 거리를 반으로 나누어 풀었다.
arr배열에 이동거리가 1씩 증가할 때 전체 이동거리를 저장하고
x와 y의 거리를 반 나눈 후 나머지가 있다면 +1 한 값을  dist에 저장,
arr[i]만큼 간 거리가 크거나 같다면 반복문을 나온다. 반만큼 갔을 때 i = 작동횟수
arr[i-1]만큼 되돌아간다.
arr[i]+arr[i-1] 보다 작거나 같을 땐 홀수 이동횟수 , 크면 짝수이동횟수
*/

#include <cstdio>
using namespace std;

int main() 
{
	long long arr[100001],t, x, y, dist, MAX=(1<<30)+1;
	scanf("%lld", &t);
	arr[0] = 0;
	for (int i = 1; i < 100000; i++) {
		arr[i] = arr[i - 1] + i;
		if (arr[i] > MAX) break;
	}

	while (t--) {
		scanf("%lld %lld", &x, &y);
		if (y - x == 1) printf("1\n");
		else if (y - x == 2) printf("2\n");
		else {
			int i;
			dist = (y - x)/2;
			if ((y - x) % 2 != 0) dist++;
			for (i = 1; i < 100000; i++) {
				if (arr[i] >= dist) break;
			}
			if (arr[i] + arr[i - 1] < y-x) {
				printf("%d\n", i * 2);
			}
			else printf("%d\n", i * 2-1);
		}
	}

	return 0;
}