/*
cmp로 오름,내림차순 정렬을 정의했다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;
};

bool cmp(student x,student y){
	if (x.korean != y.korean) {
		return x.korean > y.korean;
	}
	if (x.english != y.english) {
		return x.english < y.english;
	}
	if (x.math != y.math) {
		return x.math > y.math;
	}
	return x.name < y.name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;
	cin >> n;
	student *stu = new student[n];
	for (i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].korean >> stu[i].english >> stu[i].math;
	}
	sort(stu, stu + n, cmp);
	for (i = 0; i < n; i++) {
		cout << stu[i].name << "\n";
	}

	return 0;
}