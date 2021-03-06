/*
n이 음수일 때 만약 홀수라면 n%-2 나머지가 -1이 된다
나머지를 1로 만들어 주기위해 다음 수로 n-1/-2를 한다. 
n이 음수이고 짝수일 때 n%-2 는 0이지만 n-1를 해주어도 다음 계산은 똑같은 값이
들어가기 때문에 음수일때 모두 n-1/-2를 해준다
*/
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n,len;
	string st="";
	scanf("%d", &n);
	if (n == 0) st = "0";
	while (n!=0) {
		st+= abs(n % (-2))+'0';
		n = n > 0 ? n / -2 : (n - 1) / -2;
	}
	len = st.size();
	for (int i = len - 1; i >= 0; i--) printf("%c", st[i]);

	return 0;
}