/*
우선순위 큐 최솟값 나오는 것
*/
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> q;
	int n,x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x == 0) {
			if (q.empty()) printf("0\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else q.push(x);
	}
	
	return 0;
}