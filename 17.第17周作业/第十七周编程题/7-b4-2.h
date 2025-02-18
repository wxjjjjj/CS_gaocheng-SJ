/* 2353761 王皙晶 计科 */
#pragma once

/* 允许加入需要的头文件、命令空间 */
#include<cmath>
class triangle;  //类的提前声明，思考一下，放在这里的目的是为什么

/* point类的定义及实现，已给出部分内容，按要求补充完成 */
class point {
private:
	int x;
	int y;
public:
	/* 仅允许在此添加一个成员函数【仅限1个】,要求体内实现 */
	void set(int m, int n)
	{
		x = m;
		y = n;
		return;
	}
	/* 除上面允许的那个成员函数外，不再允许添加任何的数据成员和成员函数，但可以根据需要添加其它内容 */
	friend class triangle;      //友元类访问私有成员
};

/* triangle类的定义及实现，已给出部分内容，按要求补充完成 */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员
public:
	/* 构造函数（已实现，不准动） */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}

	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，
           要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		double a, b, c;
		a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
		b = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
		c = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y- p3.y));
		if ((a + b > c) && (a + c > b) && (b + c > a) && (fabs(a - b) < c) && (fabs(a - c) < b) && (fabs(b - c) < a)) {
			return double(abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y))) / 2;
		}
		else {
			return -1;
		}
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */

};
