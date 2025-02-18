/*2353761 王皙晶 计科*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

void shuru(int score[], char name[][9], char xuehao[][8])
{
	for (int i = 0; i < 10; ++i) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", &xuehao[i]);
		scanf("%s", &name[i]);
		scanf("%d", &score[i]);
	}
	return;
}
void select(int score[], char name[][9], char xuehao[][8])
{
	int k, t;
	char tmp_name[9] = { 0 }, tmp_xuehao[8] = { 0 };
	for (int i = 0; i < 9; i++) {
		k = i;
		for (int j = i + 1; j < 10; j++) {
			if (score[j] > score[k]) {
				k = j;
			}
		}//得到最“大”的成绩的下标
		t = score[i];
		for (int x = 0; x < 9; ++x) {
			tmp_name[x] = name[i][x];
		}
		for (int x = 0; x < 8; ++x) {
			tmp_xuehao[x] = xuehao[i][x];
		}

		score[i] = score[k];
		for (int x = 0; x < 9; ++x) {
			name[i][x] = name[k][x];
		}
		for (int x = 0; x < 8; ++x) {
			xuehao[i][x] = xuehao[k][x];
		}

		score[k] = t;
		for (int x = 0; x < 9; ++x) {
			name[k][x] = tmp_name[x];
		}
		for (int x = 0; x < 8; ++x) {
			xuehao[k][x] = tmp_xuehao[x];
		}
	}
	return;
}
void print(int score[], char name[][9], char xuehao[][8])//选择法排序
{
	printf("\n");
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i < 10; ++i) {
		printf("%s %s %d\n", name[i], xuehao[i], score[i]);
	}

	return;
}
int main()
{
	char xuehao[10][8] = { 0 }, name[10][9] = { 0 };
	int score[10] = { 0 };

	shuru(score, name, xuehao);
	select(score, name, xuehao);
	print(score, name, xuehao);

	return 0;
}