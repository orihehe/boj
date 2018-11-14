/*
어떻게 풀어야 할지는 알았지만 구현을 못하겠어서 백준님 슬라이드를 봤다.
짝x짝 일 때 a와 b가 만난다고 생각하고 풀었다. 다른 사람 코드는 되게 짧은 거 같은데
구현을 잘 못해서 되게 길어졌다 ㅠㅠ
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c, minNum=1001, minC, minR, i, j, arr[1000][1000];
int main()
{
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
			if ((i + j + 2) % 2 == 1 && minNum>arr[i][j]) {
				minNum = arr[i][j];
				minC = j; minR = i;
			}
		}
	}
	if (r % 2 == 1) {
		for (i = 1; i <= r; i++) {
			for (j = 1; j < c; j++) {
				if (i % 2 == 1) {
					printf("R");
				}
				else {
					printf("L");
				}
			}
			if (i == r) 
				break;
			printf("D");
		}
	}
	else if (c % 2 == 1) {
		for (i = 1; i <= c; i++) {
			for (j = 1; j < r; j++) {
				if (i % 2 == 1) {
					printf("D");
				}
				else {
					printf("U");
				}
			}
			if (i == c)
				break;
			printf("R");
		}
	}
	else { 
		int aC = 0, aR = 0, bC = c-1, bR=r-1; // a는 0,0 b는 r-1, c-1 두개를 만나게
		int tmpR=minR;
		arr[minR][minC] = 0;
		string A = "", B = "";
		if (minC % 2 == 0) {  // minR이 홀수
			tmpR--;
		}
		while (tmpR - aR > 0) {
			aR += 2;
			for (i = 1; i <= 2; i++) {
				for (j = 1; j < c; j++) {
					if (i % 2 == 1) {
						A += 'R';
					}
					else {
						A += 'L';
					}
				}
				A += 'D';
			}
		}
		tmpR++;
		while (bR-tmpR > 0) {
			bR -= 2;
			for (i = 1; i <= 2; i++) {
				for (j = 1; j < c; j++) {
					if (i % 2 == 1) {
						B += 'R';
					}
					else {
						B += 'L';
					}
				}
				B += 'D';
			}
		}
		int idxA = 1, idxB = 1;
		while (true) {
			if (idxA % 2 == 0) {
				aC++;
				if (arr[aR][aC] == 0) {
					break;
				}
				A += 'R';
			}
			else if (idxA%4== 1) {
				aR++;
				if (arr[aR][aC] == 0) {
					break;
				}
				A += 'D';
			}
			else {
				aR--; 
				if (arr[aR][aC] == 0) {
					break;
				}
				A += 'U';
			}
			idxA++;
		}
		while (true) {
			if (idxB % 2 == 0) {
				bC--;
				if (arr[bR][bC] == 0) {
					break;
				}
				B += 'R';
			}
			else if (idxB % 4 == 1) {
				bR--;
				if (arr[bR][bC] == 0) {
					break;
				}
				B += 'D';
			}
			else {
				bR++;
				if (arr[bR][bC] == 0) {
					break;
				}
				B += 'U';
			}
			idxB++;
		}

		reverse(B.begin(), B.end());
		cout << A << B << "\n";
	}

	return 0;
}