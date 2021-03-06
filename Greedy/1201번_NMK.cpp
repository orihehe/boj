/*
처음 내가 풀었을때 그룹이 나오지 않는 조건이 틀렸다.
찾아보고나서 m + k - 1 <= n && n <= m * k 이 조건이 잘 이해되진 않는다.
다른 사람 코드에서 그룹을 나누는 방식부분도 잘 모르겠어서 그부분은 바꿔서 짰다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, k,len=0,remain;
	scanf("%d %d %d", &n, &m, &k);

	if (m + k - 1 <= n && n <= m * k) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			arr[i] = i+1;
		}  
		// m개의 감소하는 수열
		// 적어도 하나는 k개의 감소하는 수열
		// idx는 그룹의 시작 인덱스, temp는 끝인덱스
		reverse(arr.begin(), arr.begin() + k);  // 맨앞 k개의 감소 수열 하나 만듦
		//그룹당 숫자 수 len
		//이제 각 그룹 개수는 방금만든 하나 제외 (m-1)개 나온다 
		if (n - k > 0) {
			len = (n - k) / (m - 1);
			remain = (n - k) % (m - 1);  // 남은 수 만큼 다른 그룹에 나눠준다
		}
		int idx = k, temp = idx + len;
		while (idx < n) {
			if (remain > 0) {
				temp++;
				remain--;
			}
			reverse(arr.begin() + idx, arr.begin() + temp);
			idx = temp;
			temp += len;
		}

		for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	}
	else {
		printf("-1");
	}

	return 0;
}