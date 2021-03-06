/*
x좌표 증가하는 순으로, x가 같다면 y좌표 증가하는 순서로
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int n,x,y;
	vector<pair<int, int>> vec;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		vec.push_back(make_pair(x,y));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", vec[i].first, vec[i].second);
	}

	return 0;
}