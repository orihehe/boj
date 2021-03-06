/*
시간복잡도가 O(N)이어야 풀 수 있다.
방법을 못 찾아서 검색해보니 스택문제였다. 스택일줄 전혀 몰랐다..
각 사람은 뒤쪽 혹은 앞쪽에 본인보다 큰 사람이 있다면 그 사람 뒷사람과는 쌍을 만들 수 없다.

스택요소 first = 키, second = 그 키를 가진사람의 연속 수
스택이 비어있지 않고 맨 위의 요소x가 본인보다 작으면 x는 본인 뒤의 사람을 보지 못한다.
또 x가 본인보다 크면 본인은 x 뒤의 사람을 보지 못한다.
x가 본인과 같다면 본인은 본인보다 큰 사람이 나올때까지 x사람, 그 뒷사람을 볼 수 있다.

따라서 x와 본인이 같을 경우 x를 pop하고 cnt에 x.second를 더한 후 x.second에 +1을 하고 다시 넣는다.
x가 본인보다 작은 경우 cnt에 x.second를 더한 후 pop해준다
*/

#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int n, h;
	long long cnt = 0;
	stack<pair<int,int>> sta;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &h);
		while (!sta.empty() && sta.top().first < h) {
			cnt+=sta.top().second;
			sta.pop();
		}
		if (!sta.empty() && sta.top().first == h) {
			int tmp = sta.top().second;
			sta.pop();
			cnt += (long long)tmp;
			sta.push({ h,tmp + 1 });
		}
		else sta.push({ h,1 });
		if(sta.size() > 1) cnt++;
	}
	printf("%lld", cnt);

	return 0;
}