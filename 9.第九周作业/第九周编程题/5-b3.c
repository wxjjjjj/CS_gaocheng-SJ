#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int runnian(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
		return 1;
	}
	return 0;
}

int day(int year, int runnian, int month, int days) {   //不能用选择语句那就用二维数组！！！
	int i, sum = 0;
	//每月的天数存储在数组中
	int a[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31} };//a[0]存的是非闰年 a[1]存的是闰年
	//输入错误处理
	if (month <= 0 || month >= 13) {
		printf("输入错误-月份不正确\n");
		return 0;
	}
	if (a[runnian][month - 1] < days || days <= 0) {
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	//计算天数
	for (i = 0; i < month - 1; ++i) {
		sum = a[runnian][i] + sum;
	}
	sum = sum + days;
	return sum;

}

int main()
{
	printf("请输入年，月，日\n");
	int a, b, c, d, sum;
	scanf("%d %d %d", &a, &b, &c);          //a是年，b是月，c是日 
	d = runnian(a);     //d为1，则是闰年；0为非闰年
	sum = day(a, d, b, c);
	if (sum == 0) {
		return 0;
	}
	printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, sum);
	return 0;
}