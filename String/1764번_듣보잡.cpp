/*
입력을 모두 한 배열에 넣어 정렬을 하면 연속된 문자열이 같으면 듣보잡이다.
같은 문자열의 인덱스를 벡터에 넣고 문자열을 출력했다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string list[1000000], tmp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,cnt=0;
	vector<int> vec;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> list[i];
	}
	sort(list, list + n + m);
	for (int i = 1; i < n + m; i++) {
		if (list[i] == list[i - 1]) {
			cnt++;
			vec.push_back(i);
			i++;
		}
	}
	cout << cnt << "\n";
	int len = vec.size();
	for (int i = 0; i < len; i++) {
		cout << list[vec[i]] << "\n";
	}
	
	return 0;
}