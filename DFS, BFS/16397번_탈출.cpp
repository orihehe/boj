/*
백준 홍익대 대회 문제이다. 당시에 이 문제를 어떻게 풀지 몰랐는데 bfs로 탐색을 
하면 되는 거였다. 다른 비슷한 문제를 풀다가 생각나서 풀었다.
원래 이런 문제를 풀때 큐에 처음 경우를 넣고 시작했는데 다른 분 코드를 보고
처음에 n을 넣으면 더 간결한 코드를 짤 수 있는 걸 알았다.
*/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[100000];
int main() {
	int n, t, g, size, cnt=0;
	queue<int> q;
	bool suc = false; // 성공여부
	scanf("%d %d %d", &n, &t, &g);
	if (n == g) {
		printf("0");
		return 0;
	}
	q.push(n);
	size = q.size();
	while (!q.empty()) {
		if (size == 0) {
			size = q.size();
			cnt++;
		}
		if (cnt > t) {
			break;
		}
		int next = q.front();
		q.pop();
		if (next == g) {
			suc = true;
			break;
		}
		if (next + 1 <= 99999 && !visited[next + 1]) {
			q.push(next + 1);
			visited[next + 1] = true;
		}
		if (next!=0 && next * 2 <= 99999) {
			next *= 2;
			int tmp = 10000;
			while (next / tmp == 0) {
				tmp /= 10;
			}
			next = next - tmp;
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
		size--;
	}
	if (suc) {
		printf("%d", cnt);
	}
	else {
		printf("ANG");
	}

	return 0;
}