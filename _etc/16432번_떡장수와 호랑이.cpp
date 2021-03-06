/*
배열 arr에 i번째 날에 만든 떡 개수=arr[i][0] 만든 떡 종류(1~9)를 저장했다.
만든 떡 종류가 1개일 때 i와 떡 종류를 큐에 넣어주었다.
떡 종류가 하나인 날은 무조건 호랑이에게 그 떡을 줘야한다.
큐의 원소를 하나씩 빼면서 i-1, i+1의 x종류 떡이 있다면 0으로 만들어주고 떡종류--를 했다
그때 떡 종류가 0이된다면 동희는 잡아먹히고, 1이된다면 큐에 i와x를 넣어준다.
이것은 큐가 빌때까지 반복된다.
이 과정을 통과했다면 남은 떡 종류 아무거나 호랑이에게 줘도 된다.
*/
#include <cstdio>
#include <queue>
using namespace std;

int n, m, a, arr[1000][10], x, st;
int main()
{
	queue<pair <int, int>> que; // 앞 인덱스, 뒤 떡 종류
	pair<int, int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		arr[i][0] = m;
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			if (m == 1) {
				que.push(make_pair(i, x));
			}
			arr[i][x] = 1;
		}
	}
	while (!que.empty()) {
		v = que.front();
		que.pop();
		if (v.first > 0) {
			if (arr[v.first - 1][v.second] != 0) {
				arr[v.first - 1][0]--;
				arr[v.first - 1][v.second] = 0;
				if (arr[v.first - 1][0] == 0) {
					st = -1;
					break;
				}
				else if (arr[v.first - 1][0] == 1) {
					for (int i = 1; i < 10; i++) {
						if (arr[v.first - 1][i] != 0) {
							que.push(make_pair(v.first - 1, i));
							break;
						}
					}
				}
			}
		}
		if (v.first < n - 1) {
			if (arr[v.first + 1][v.second] != 0) {
				arr[v.first + 1][0]--;
				arr[v.first + 1][v.second] = 0;
				if (arr[v.first + 1][0] == 0) {
					st = -1;
					break;
				}
				else if (arr[v.first + 1][0] == 1) {
					for (int i = 1; i < 10; i++) {
						if (arr[v.first + 1][i] != 0) {
							que.push(make_pair(v.first + 1, i));
							break;
						}
					}
				}
			}
		}
	}
	if (st == -1) printf("-1");
	else {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j <= 9; j++) {
				if (arr[i][j] != 0) {
					printf("%d\n", j);
					arr[i + 1][j] = 0;
					break;
				}
			}
		}
		for (int j = 1; j <= 9; j++) {
			if (arr[n - 1][j] != 0) {
				printf("%d\n", j);
				break;
			}
		}
	}

	return 0;
}