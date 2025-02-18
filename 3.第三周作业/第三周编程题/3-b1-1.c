#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	const double pi = 3.14159;
	double r, h, c, s, S, v, V;
	printf("请输入半径和高度\n");
	scanf("%lf %lf", &r, &h);
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v = 4 * pi * r * r * r / 3;
	V = pi * r * r * h;

	printf("圆周长     : %.2lf\n", c);
	printf("圆面积     : %.2lf\n", s);
	printf("圆球表面积 : %.2lf\n", S);
	printf("圆球体积   : %.2lf\n", v);
	printf("圆柱体积   : %.2lf\n", V);


	return 0;

}



















































