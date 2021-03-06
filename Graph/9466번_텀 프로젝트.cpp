/*
사이클을 이루는 부분은 프로젝트 팀을 구성할 수 있다는 것을 나타낸다.

주석부분은 내가 처음에 짠 코드인데 시간초과가 난 것이다.
cycle배열에 dfs를 하면서 들른 노드들을 저장하여 만약 다음 요소가 이미 방문했고
cycle배열에 있다면 싸이클을 이루지 않는 요소들만큼 cnt를 증가시켰었다. 
그래서 cycle배열 초기화를 포문안에 했었다.

다른 사람 코드를 참고하여 다시 짠 코드는
cycle배열은 싸이클 검사를 한 후 모두 1로 바꾸고, 만약 다음 요소가 방문을 했고
cycle배열이 0이라면 다음 요소를 차례로 방문하여 싸이클인 노드 수를 카운트했다.
모두 카운트 후 n-cnt를 하여 싸이클을 이루지 않는 요소 수를 출력해줬다.
*/
#include <cstdio>
#include <vector>
using namespace std;

int visited[100000];
int cycle[100000];
vector<int> vec;
int t, n, x, cnt;
void dfs(int start) {
	int next = vec[start];
	if (visited[next]==0) {
		visited[next] = 1;
		dfs(next);
	}
	else {
		if (cycle[next] == 0) {
			cnt++;  // i=start
			for (int i = next; i != start; i=vec[i]){
				cnt++;
			}
		}
		/*bool isThere = false;
		for (int i = 0; i < ctop; i++) {
			if (cycle[i] == next) {
				cnt += i;
				isThere = true;
				ctop = 0;
				break;
			}
		}
		if (!isThere) {
			cnt += ctop;
			ctop = 0;
		}*/
	}
	cycle[start] = 1;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vec.clear();
		vec.resize(n);
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		memset(cycle, 0, sizeof(cycle));
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			vec[i]=(x-1);
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				dfs(i);
			}
		}
		printf("%d\n", n-cnt);
	}

	return 0;
}