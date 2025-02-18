#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cout << "请输入一个[1..30000]的整数:" << endl;
	cin >> a;
	b = a % 10;                     //个位数字
	a = a / 10;
	c = a % 10;					    //十位数字
	a = a / 10;
	d = a % 10;						//百位数字
	a = a / 10;
	e = a % 10;						//千位数字
	a = a / 10;
	f = a % 10;						//万位数字
	cout << "万位 : " << f << endl;
	cout << "千位 : " << e << endl;
	cout << "百位 : " << d << endl;
	cout << "十位 : " << c << endl;
	cout << "个位 : " << b << endl;
	return 0;
}
