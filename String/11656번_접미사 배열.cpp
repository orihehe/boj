#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string st[1000];
	int len;
	cin >> st[0];
	len = st[0].size();
	for (int i = 1; i < len; i++) {
		st[i] = st[0];
		st[i].erase(0, i);
	}
	sort(st, st+len);
	for (int i = 0; i < len; i++) {
		cout << st[i] << "\n";
	}

	return 0;
}