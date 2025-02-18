/*2353761 王皙晶 计科*/
#include<iostream>
#include<string>

using namespace std;

void shuru(string xuehao[], string name[], int score[10])
{
	for (int i = 0; i < 10; ++i) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> xuehao[i];
		cin >> name[i];
		cin >> score[i];
	}
	return;
}
void select(string xuehao[], string name[], int score[10])
{
	int k,m;
	string s1, s2;
	for (int i = 0; i < 9; ++i) {
		k = i;
		for (int j = i + 1; j < 10; ++j) {
			if (score[j] < score[k]) {
				k = j;
			}
		}//找出最小值的下标
		m = score[i];
		s1 = xuehao[i];
		s2 = name[i];
		score[i] = score[k];
		xuehao[i] = xuehao[k];
		name[i] = name[k];
		score[k] = m;
		xuehao[k] = s1;
		name[k] = s2;
	}
	return;
}
void print(string xuehao[], string name[], int score[10])
{
	cout << endl;
	cout << "不及格名单(成绩升序):" << endl;
	for (int i = 0; i < 10; ++i) {
		if (score[i] < 60) {
			cout << name[i] << ' ' << xuehao[i] << ' ' << score[i] << endl;
		}
	}
	return;
}
int main()
{
	string xuehao[10], name[10];
	int score[10];
	shuru(xuehao,name,score);
	select(xuehao, name, score);
	print(xuehao, name, score);
	return 0;
}