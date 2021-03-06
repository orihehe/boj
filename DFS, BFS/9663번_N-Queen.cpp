/*
board 배열의 i번째 값 x는 i열에 x번째 행에 퀸을 놓는 다는 것
queen함수에서 현재 c번째 열에 퀸을 놓을 수 있는지를 검사한다
왼쪽 위아래 대각선과 왼쪽직선 위치에 말이 놓여져있다면 진행하지 않는다.
*/
#include <cstdio>
using namespace std;

int n,cnt;
int board[15];

void queen(int c) {
	if (c == n) {
		cnt++; return;
	}
	bool check;
	for (int i = 0; i < n; i++) {
		check = true;
		for (int j = 0; j < c; j++) {
			if (i == board[j] || board[j]== i-(c-j) || board[j]==i+(c-j)) {
				check = false;
				break;
			}
		}
		if (check) {
			board[c] = i;
			queen(c + 1);
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	queen(0);
	printf("%d", cnt);

	return 0;
}
