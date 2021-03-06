/*
m배열에 m[i]를 밟았을 때의 최대값을 저장한다.
N(x)=max(N(x-2),N(x-3)+arr[x-1])+arr[x]
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[301],m[301];
int stair(int start) {
	int a, b;
	if (m[start] != 0) return m[start]; 
	
	a = stair(start - 3);
	b = stair(start - 2);
	m[start] = max(a + arr[start - 1], b) + arr[start];
	return m[start];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if(n>0)m[0] = arr[0];
	if (n>1)m[1] = arr[0] + arr[1];
	if (n>2)m[2] = max(arr[0], arr[1]) + arr[2];
	printf("%d\n",stair(n-1));

	return 0;
}