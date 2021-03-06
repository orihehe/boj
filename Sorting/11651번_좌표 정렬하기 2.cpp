/*
11650번 좌표정렬하기 코드에 x,y 위치만 바꾸면 된다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, x, y;
	vector<pair<int, int>> vec;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		vec.push_back(make_pair(y, x));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", vec[i].second,vec[i].first);
	}

	return 0;
}