/*
우선 수열을 오름차순 정렬한다
M+m을 가능한 작게 만드는 것이므로 k개의 원소를 뺀 수열을 연속한 값들로 둔다.
수열의 끝 원소 - 첫 원소가 가장 큰 차이다.
가장 작은 차이 m은 연속한 두 원소의 차이들 중 가장 작은 값이다.
이는 슬라이딩 윈도우 기법으로 백준 11003번 최솟값찾기 (https://www.acmicpc.net/problem/11003) 방법으로 찾았다.
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#define P pair<long long,long long>
using namespace std;

int main() {
	long long n, k, i, minD, maxD, minS;
	priority_queue<P, vector<P>, greater<P>> pq;
	scanf("%lld %lld", &n, &k);
	vector<long long> vec;
	vec.resize(n);
	for (i = 0; i < n; i++) {
		scanf("%lld", &vec[i]);
	}
	sort(vec.begin(), vec.end());

	maxD = vec[n - k - 1] - vec[0];
	for (i = 0; i <= n - k - 2; i++) {
		pq.push({ vec[i + 1] - vec[i], i });
	}
	minD = pq.top().first;
	minS = maxD + minD;
	//i는 시작idx
	for (i = 1; i <= n - (n-k); i++) {
		long long dis = i + (n - k) - 1; // dis는 끝idx
		pq.push({ vec[dis] - vec[dis - 1], dis-1 });
		maxD = vec[dis] - vec[i];
		while (pq.top().second <i) {
			pq.pop();
		}
		minD = pq.top().first;
		minS = min(maxD + minD, minS);
	}
	printf("%lld", minS);

	return 0;
}