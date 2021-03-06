/*
ti가 1인 경우 공격력이 a이고 생명력이 h인 몬스터가 있음을 나타내고, 
ti가 2인 경우 용사의 공격력 HATK를 ai만큼 증가시켜주고 용사의 현재 생명력을
hi만큼 회복시켜주는 포션이 있음을 나타냅니다.

attack = 용사의 공격력
hp(용사의 생명력)을 0으로 두고, t가 1일 때 용사가 몇번 공격해야 몬스터가
쓰러지는지 횟수(kill)을 구하여 hp에 (kill-1)*몬스터 공격력 을 빼주었다.
이때 최솟값을 minhp에 저장했다.
t가 2일 때 용사의 공격력을 증가시키고, hp는 최대치를 넘을 수 없으니 양수가 됐을 때
0으로 초기화 시켰다.
용사는 minhp+1 만큼의 체력이 있다면 공주를 구할 수 있을 것이다.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	long long n, attack, t, a, h, hp = 0, kill, minhp = 0;
	scanf("%lld %lld", &n, &attack);
	while (n--) {
		scanf("%lld", &t);
		kill = 0;
		if (t == 1) {
			scanf("%lld %lld", &a, &h);
			if (h%attack != 0) kill = 1;
			kill += h / attack;
			hp -= (kill - 1)*a;
			if (hp < minhp) minhp = hp;
		}
		if (t == 2) {
			scanf("%lld %lld", &a, &h);
			hp += h;
			if (hp > 0) hp = 0;
			attack += a;
		}
	}
	printf("%lld", abs(minhp) + 1);

	return 0;
}