#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, x, xx, mid, left, right, find;
	vector<int> vec;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &xx);
		vec.push_back(xx);
	}
	sort(vec.begin(), vec.end());
	scanf("%d", &m);
	while (m--) {
		left = 0;
		right = n - 1;
		find = 0;
		scanf("%d", &x);
		while (left <= right) {
			mid = (left + right) / 2;
			if (vec[mid] > x) {
				right = mid - 1;
			}
			else if (vec[mid] < x) {
				left = mid + 1;
			}
			else {
				find = 1;
				break;
			}
		}
		printf("%d ", find);
	}

	return 0;
}