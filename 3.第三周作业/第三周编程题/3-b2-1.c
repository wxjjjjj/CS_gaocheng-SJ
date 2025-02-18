#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>


int main()
{
	int a, b, c, d, e, f;
	printf("请输入一个[1..30000]的整数:\n");
	scanf("%d", &a);
	b = a % 10;                     //个位数字
	a = a / 10;
	c = a % 10;					    //十位数字
	a = a / 10;
	d = a % 10;						//百位数字
	a = a / 10;
	e = a % 10;						//千位数字
	a = a / 10;
	f = a % 10;						//万位数字

	printf("万位 : %d\n", f);
	printf("千位 : %d\n", e);
	printf("百位 : %d\n", d);
	printf("十位 : %d\n", c);
	printf("个位 : %d\n", b);
	
	return 0;
}
