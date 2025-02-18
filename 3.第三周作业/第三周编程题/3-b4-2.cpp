#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


int main()
{
	int a, b, c;
	double d;
	float s;
	const double pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a>> b>>c;
	d = c * pi/180;
	s = a * b * float(sin(d)) / 2;
	cout << std::fixed << std::setprecision(3) << "三角形面积为 : " << s<< endl;
	return 0;

}
