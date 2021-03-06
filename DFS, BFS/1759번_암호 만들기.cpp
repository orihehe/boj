#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int l, c, mo, ja;
char x;
vector<char> vec;
bool visited[15];
bool alpha[26];
void dfs(int start, int len) {
	visited[start] = true;
	if (len == l) {
		mo = 0;
		ja = 0;
		string st = "";
		for (int i = 0; i < c; i++) {
			if (visited[i] == true) {
				if (alpha[vec[i] - 'a']) mo++;
				else ja++;
				st += vec[i];
			}
		}
		if (ja>=2 && mo >= 1) {
			printf("%s\n", st.c_str());
		}
	}
	if (len < l) {
		for (int i = start + 1; i < c; i++)
			dfs(i, len + 1);
	}
	visited[start] = false;
}

int main()
{
	alpha['a' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['e' - 'a'] = true; 
	alpha['u' - 'a'] = true;
	alpha['o' - 'a'] = true;
	scanf("%d %d ", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %c", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i <= c - l; i++) {
		dfs(i, 1);
	}

	return 0;
}