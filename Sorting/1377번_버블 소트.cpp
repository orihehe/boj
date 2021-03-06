/*
원래 자리와 정렬 후 자리가 차이가 제일 큰 값을 출력해줬다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int, int>> vec;
	int n, tmp, maxc = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		vec.push_back(make_pair(tmp,i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (vec[i].second - i > maxc)maxc = vec[i].second - i;
	}
	cout << maxc + 1 << "\n";

	return 0;
}