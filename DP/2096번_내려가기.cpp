#include <cstdio>
#include <algorithm>
using namespace std;

int minarr[3];
int maxarr[3];
int main() {
	int n,a,b,c,mina=0,minb=0,minc=0,maxa=0,maxb=0,maxc=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a,&b,&c);
		mina = a+min(minarr[0], minarr[1]);
		minb = b+min({ minarr[0], minarr[1],minarr[2] });
		minc = c+min(minarr[1], minarr[2]);
		minarr[0] = mina;
		minarr[1] = minb;
		minarr[2] = minc;
		maxa = a + max(maxarr[0], maxarr[1]);
		maxb = b + max({ maxarr[0], maxarr[1],maxarr[2] });
		maxc = c + max(maxarr[1], maxarr[2]);
		maxarr[0] = maxa;
		maxarr[1] = maxb;
		maxarr[2] = maxc;
	}
	printf("%d %d", max({ maxarr[0], maxarr[1],maxarr[2] }),
		min({ minarr[0], minarr[1],minarr[2] }));

	return 0;
}