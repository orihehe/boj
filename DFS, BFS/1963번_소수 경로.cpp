/*
처음엔 dfs로 풀었다. used배열에 n숫자 까지 가는데 바꾼 횟수를 저장해두고, 
used에 저장된 횟수보다 현재 큰 횟수일땐 그 숫자로 탐색을 가지 않았다. 
이렇게 하면 점점 작은 횟수가 나오면 계속 들어가 갱신을 해줘 시간이 오래 걸렸다. (1020ms)
시간이 너무 많이 나와서 검색을 해보니 bfs문제였다.
bfs는 깊이별로 카운트를 하여 목표한 수를 찾으면 멈춰 바로 출력하면 된다.
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int used[10000];
bool sosu[10000]; // false면 소수
int t, now, want, minCnt;

//dfs
void func(int cnt, int cur) {  // cnt:몇번 바꿨는지, cur:현재 숫자
	if (cur == want) {
		minCnt = min(minCnt, cnt);
	}
	if (cnt > minCnt) 
		return;
	for (int i = 1; i < 1001; i *= 10) {
		for (int j = 0; j < 10; j++) {
			if (i == 1000 && j == 0) continue;
			int next = cur - ((cur / i)%10)*i + i * j;
			if (used[next]>cnt && !sosu[next]) {
				used[next] = cnt;
				func(cnt + 1, next);
			}
		}
	}

}

int main() {
	sosu[1] = true;
	for (int i = 2; i <= 5000; i++) {
		for (int j = 2; j*i <= 9999; j++) {
			sosu[i*j] = true;
		}
	}
	// now:현재숫자, want:바꾸려는 숫자
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &now, &want);
		minCnt = 10001;
		queue<int> q;
		//fill(used, used + 10000, 10001);
		//used[now] = 0;
		//func(0, now);
		fill(used, used + 10000, 0);
		if (now == want) {
			printf("0\n");
			continue;
		}
		for (int i = 1; i < 1001; i *= 10) {
			for (int j = 0; j < 10; j++) {
				if (i == 1000 && j == 0) continue;
				int next = now - ((now / i) % 10)*i + i * j;
				if (!sosu[next]) {
					used[next] = 1;
					q.push(next);
				}
			}
		}
		bool posi=false;
		int size = q.size(), cnt = 1;
		while (!q.empty()) {
			if (size == 0) {
				size = q.size();
				cnt++;
			}
			int next = q.front();
			q.pop();
			if (next == want) {
				posi = true;
				break;
			}
			for (int i = 1; i < 1001; i *= 10) {
				for (int j = 0; j < 10; j++) {
					if (i == 1000 && j == 0) continue;
					int nextNum = next - ((next / i) % 10)*i + i * j;
					if (used[nextNum]==0 && !sosu[nextNum]) {
						used[next] = nextNum;
						q.push(nextNum);
					}
				}
			}
			size--;
		}

		if (!posi) printf("Impossible\n");
		else printf("%d\n", cnt);
	}

	return 0;
}