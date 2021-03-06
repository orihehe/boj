/*
문제를 잘못 이해해서 fun배열에 인덱스와 대기시간을 같이 넣어서 대기시간 오름차순
sort를 해서 계속 틀렸다.ㅠㅠ
시간이 mid만큼 흘렀을 때 탈 수 있는 인원수를 세서 n보다 크거나 같을 때 runtime에
저장한다.
runtime 이전에 탑승한 사람을 빼주고 runtime에 탑승한 사람을 찾는다.
*/
#include <cstdio>
#include <algorithm>
#define P pair<long long,long long>
using namespace std;

int main() {
	long long n, m;
	long long fun[10001];
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &fun[i]);
	}
	long long left=0, right= 60000000000, mid, people, runtime; // mid는 전체운행시간
	while (left <= right) {
		mid = (left + right) / 2;
		people = 0; // mid운행시간동안 몇명 태우는지
		for (int i = 1; i <= m; i++) {
			people += (mid+fun[i]-1)/fun[i];
		}
		if (people >= n) {
			right = mid - 1;
			runtime = mid;
		}
		else {
			left = mid + 1;
		}
	}
	//runtime만큼 운행하면 m명은 태울 수 있음
	//printf("runtime:%lld\n", runtime);
	runtime--;
	for (int i = 1; i <= m; i++) {
		n -= (runtime + fun[i] - 1) / fun[i];
	}
	for (int i = 1; i <= m; i++) {
		if (runtime % fun[i] == 0) {
			n--;
		}
		if (n == 0) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}