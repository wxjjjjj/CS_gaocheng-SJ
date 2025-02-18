#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("请输入找零值：\n");
	double a, d;
	int p, q;
	scanf("%lf", &a);
	a = a + 0.005;                              //弥补实数误差，如果是三位小数就要更小-0.0005，以此类推
	int c;
	c = (int)a;									//将浮点数的整数部分存在c中
	d = a - c;								    //将小数部分存在d中

	p = (int)(d * 10);                            //角位数字p
	q = (int)((d - p * 0.1) / 0.01);              //分位数字q

	int b, e, f, g, h, i, j, k;
	b = c / 50;                 //b为50找零的张数
	e = c % 50;             //c为找50后剩下的钱
	f = e / 20;				//f为20找零的张数
	g = e % 20;
	h = g / 10;				//h为10找零的张数
	i = g % 10;
	j = i / 5;				//j为5找零的张数
	k = i % 5;              //k既是找5剩下的钱，也是找1元的张数

	int l, m, n, r, s, t;
	l = p / 5;
	m = p % 5;				//m既是找5剩下的钱，也是找1的张数

	n = q / 5;
	r = q % 5;
	s = r / 2;
	t = r % 2;				//t既是找2剩下的钱，也是找1的张数

	int sum;
	sum = b + f + h + j + k + l + m + n + s + t;

	printf("共%d张找零，具体如下：\n",sum);
	if (b != 0) {
		printf("50元 : %d张\n", b);
	}
	if (f != 0) {
		printf("20元 : %d张\n", f);
	}
	if (h != 0) {
		printf("10元 : %d张\n", h);
	}
	if (j != 0) {
		printf("5元  : %d张\n", j);
	}
	if (k != 0) {
		printf("1元  : %d张\n", k);
	}
	if (l != 0) {
		printf("5角  : %d张\n", l);
	} 
	if (m != 0) {
		printf("1角  : %d张\n", m);
	}
	if (n != 0) {
		printf("5分  : %d张\n", n);
	}
	if (s != 0) {
		printf("2分  : %d张\n", s);
	}
	if (t != 0) {
		printf("1分  : %d张\n", t);
	}
	return 0;
}