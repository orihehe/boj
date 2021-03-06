/*
자릿수를 p번 곱한 수를 tmp에 저장한다.
그리고 앞에서부터 vector를 탐색하여 tmp와 같은 수가 있다면 뒷부분은 반복될것이므로
반복을 멈추고 개수를 출력한다.
*/
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int a, p,i,len,tmp,index=-1, nn;
	vector<int> vec;
	scanf("%d %d", &a, &p);
	vec.push_back(a);
	while (index==-1) {
		len = vec.size();
		tmp = 0;
		nn = vec[len-1];
		while (nn > 0) {
			tmp += pow(nn%10,p);
			nn /= 10;
		}
		for (i = 0; i < len; i++) {
			if (vec[i] == tmp) {
				index = i;
				break;
			}
		}
		vec.push_back(tmp);
	}
	printf("%d\n", index);

	return 0;
}