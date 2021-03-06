#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n,x,sum=0;
	vector<int> a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	printf("%d\n", sum);

	return 0;
}