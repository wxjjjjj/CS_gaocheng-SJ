#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>


int main()
{
	printf("请输入一个[1-100亿)之间的数字:\n");
	double a, d, x;
	int e, f, g, h, i, j, k, l, m, n, p, q;
	scanf("%lf", &a);
	a = a + 0.005;                              //弥补实数误差，如果是三位小数就要更小-0.0005，以此类推
	long c;                                     //因为long long在dev中编译不通过，必须用long型
	x = a / 100;								    //将可能溢出的数据变得不溢出（最多11变9位，包不溢出） （此时两位小数变四位小数）
	c = (long)x;									//将浮点数的整数部分存在c中
	d = x - c;								    //将小数部分存在d中

	g = c % 10;									//百位数字
	c = c / 10;
	h = c % 10;									//千位数字
	c = c / 10;
	i = c % 10;									//万位数字
	c = c / 10;
	j = c % 10;									//十万位数字
	c = c / 10;
	k = c % 10;									//百万位数字
	c = c / 10;
	l = c % 10;									//千万位数字
	c = c / 10;
	m = c % 10;									//亿位数字
	c = c / 10;
	n = c % 10;									//十亿位数字

	p = (int)(d * 10);                            //十位数字
	q = (int)((d - p * 0.1) / 0.01);			 //圆位数字
	e = (int)((d - 0.1 * p - 0.01 * q) / 0.001);	//角位数字
	f = (int)((d - 0.1 * p - 0.01 * q - 0.001 * e) / 0.0001);	//分位数字

	printf( "十亿位 : %d\n", n);
	printf("亿位   : %d\n", m);
	printf("千万位 : %d\n", l);
	printf("百万位 : %d\n", k);
	printf("十万位 : %d\n", j);
	printf("万位   : %d\n", i);
	printf("千位   : %d\n", h);
	printf("百位   : %d\n", g);
	printf("十位   : %d\n", p);
	printf("圆     : %d\n", q);
	printf("角     : %d\n", e);
	printf("分     : %d\n", f);

	return 0;
}