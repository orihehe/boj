/*
운영체제 시간에 문제와 같은 스케줄링 기법을 배웠던 것 같다.
1. 사용하려는 전기용품이 이미 꽂혀있다면 다음 것으로
2. 꽂혀있지 않지만 남는 자리가 있다면 꽂고 다음 것으로
3. 1,2번이 아니라면 뺄 것을 찾아야 함
  tmp배열에 꽂혀있는 플러그 복사 후 뺼 플러그를 찾는다.
  지금 사용하려는 전기용품 다음것부터 차례로 플러그가 꽂혀있다면 tmp배열에서 false로 바꿔준다.
  tmp배열에 남아있는 플러그 1개가 뺄 플러그가 된다.
  만약 여러 플러그가 남아있다면 앞으로 사용되지 않는 플러그들 이므로 앞에것을 빼줬다.

if문의 순서때문에 여러번 틀렸다. 잘 체크 해야겠다.
*/
#include <cstdio>
#include <cstring>
using namespace std;

bool plug[101], tmp[101];
int main() {
	int n, k, arr[101], idx = 1, i, size = 0, out, cnt = 0;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++) {
		scanf("%d", &arr[i]);
	}
	while (idx <= k) {
		if (plug[arr[idx]]) { // 이미 꽂혀있음
			idx++;
			continue;
		}
		else if (size < n) { // 자리 비어있음
			plug[arr[idx]] = true;
			size++;
			idx++;
			continue;
		}

		// 뺄거 찾아야 함
		memcpy(tmp, plug, sizeof(tmp));
		for (i = idx + 1; i <= k; i++) {
			if (size == 1) {
				break;
			}
			if (tmp[arr[i]]) {
				tmp[arr[i]] = false;
				size--;
			}
		}
		size = n;

		for (int j = 1; j <= 100; j++) {
			if (tmp[j]) {
				out = j;
				break;
			}
		}
		plug[out] = false;
		plug[arr[idx]] = true;
		cnt++;
		idx++;
	}
	printf("%d", cnt);

	return 0;
}