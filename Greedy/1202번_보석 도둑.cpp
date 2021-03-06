/*
갖고 있는 가방 중 들 수 있는 무게가 작은 가방부터 보석을 담는다.
보석을 담을 때엔 들 수 있는 무게중 가장 가치가 큰 보석을 담는다.
처음엔 우선순위큐를 사용하긴 했지만 무게별로 만들어 현재 들 수 있는 무게보다
작은 무게들을 다 탐색해서 TLE가 났다.
일단 보석과 가방을 무게순으로 정렬, 
작은 가방부터 탐색을 하니 우선순위큐에 현재 가방이 들 수 있는 무게 이하의 보석의 가격을
우선순위큐에 넣어 최댓값을 더한다. 다음 가방이 아직 넣지않은 보석의 무게보다 무거운 걸
담을 수 있다면 큐에 넣어준다.
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#define P pair<int,int>
using namespace std;

int bag[300000];
P jj[300000];
priority_queue<int> q;
int main() {
	int n, k;
	long long sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &jj[i].first, &jj[i].second);
	}

	for (int i = 0; i < k; i++) {
		scanf("%d", &bag[i]);
	}

	sort(jj, jj + n);
	sort(bag, bag + k);

	int jidx=0;
	for (int i = 0; i < k; i++) {
		while (jidx < n && bag[i] >= jj[jidx].first) {
			q.push(jj[jidx].second);
			jidx++;
		}
		if (!q.empty()) {
			sum += (long long)q.top();
			q.pop();
		}
	}
	printf("%lld", sum);

	return 0;
}