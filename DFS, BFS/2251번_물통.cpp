/*
처음에 water에 변수 세 개 (a,b,c)로 두고 bfs부분에서 x에서 y로 붓는 경우 6가지를 다 썼다.
코드가 굉장히 길어져서 다른 사람 걸 보니 6가지 경우를 한번에 하는 걸 보고 변수를 배열로
바꾸고 다시 정리해서 풀었다.
*/
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool liter[201][201][201]; // a,b,c 리터 상태
bool cliter[201]; // c 리터 상태
struct water {
	int a[3];
};

//x 통에서 to로 붓기
void pour(int &x, int &to, int maxW) {
	if (to < maxW) {
		if (maxW - to >= x) { //to에 남은 용량이 x리터 이상이면
			to += x;
			x = 0;
		}
		else {
			x -= maxW - to;
			to = maxW;
		}
	}
}

int main() {
	int aW[3];
	queue<water> q;
	scanf("%d %d %d", &aW[0], &aW[1], &aW[2]);
	q.push({ 0,0,aW[2] });
	liter[0][0][aW[2]] = true;
	while (!q.empty()) {
		water next = q.front();
		q.pop();
		water tmp;
		if (next.a[0] == 0)
			cliter[next.a[2]] = true;
		for (int i = 0; i < 3; i++) {
			if (next.a[i] != 0) {
				for (int j = 1; j <= 2; j++) {
					tmp = next;
					pour(tmp.a[i], tmp.a[(i + j) % 3], aW[(i + j) % 3]);
					if (!liter[tmp.a[0]][tmp.a[1]][tmp.a[2]]) {
						liter[tmp.a[0]][tmp.a[1]][tmp.a[2]] = true;
						q.push(tmp);
					}
				}
			}
		}
	}
	for (int i = 0; i <= aW[2]; i++) {
		if (cliter[i]) printf("%d ", i);
	}

	return 0;
}