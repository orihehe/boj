#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

bool alpha[26];
int main() {
	char st[53];
	int cnt = 0,len;
	scanf("%s", st);
	len = strlen(st);
	stack<char> sta;
	stack<char> tmp;
	for (int i = 0; i < len; i++) {
		char a = st[i];
		if (!alpha[a-'A']) {
			sta.push(a);
			alpha[a - 'A'] = true;
		}
		else {
			while (sta.top() != a) {
				tmp.push(sta.top());
				sta.pop();
				cnt++;
			}
			sta.pop();
			while (!tmp.empty()) {
				sta.push(tmp.top());
				tmp.pop();
			}
		}
	}
	printf("%d", cnt);

	return 0;
}