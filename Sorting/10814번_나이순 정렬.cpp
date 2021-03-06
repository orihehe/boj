/*
나이순, 나이가 같다면 입력순서로 출력하는 문제이다.
vec에 나이와 입력 순서를 저장하고 이름은 따로 저장해뒀다.
나이, 입력을 오름차순 sort 하고 이름은 name[입력순]으로 출력하였다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

char name[100000][101];
int main() 
{
	int n, x;
	vector<pair<int, int>> vec; // 나이, 순서
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &x, name[i]);
		vec.push_back(make_pair(x,i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) 
		printf("%d %s\n", vec[i].first, name[vec[i].second]);

	return 0;
}