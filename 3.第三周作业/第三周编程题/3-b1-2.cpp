#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h,c,s,S,v,V;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v = 4 * pi * r * r * r / 3;
	V = pi * r * r * h;
	
	cout << std::fixed << std::setprecision(2) << "圆周长     : " << c << endl;
	cout << std::fixed << std::setprecision(2) << "圆面积     : " << s << endl;
	cout << std::fixed << std::setprecision(2) << "圆球表面积 : " << S << endl;
	cout << std::fixed << std::setprecision(2) << "圆球体积   : " << v << endl;
	cout << std::fixed << std::setprecision(2) << "圆柱体积   : " << V << endl;

	return 0;

}
