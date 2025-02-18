#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "请输入找零值：" << endl;
	double a,d;
	int p,q;
	cin >> a;
	a = a + 0.005;                              //弥补实数误差，如果是三位小数就要更小-0.0005，以此类推
	int c;                                     
	c = int(a);									//将浮点数的整数部分存在c中
	d = a - c;								    //将小数部分存在d中

	p = int(d * 10);                            //角位数字p
	q = int((d - p * 0.1) / 0.01);              //分位数字q

	int b, e, f, g, h, i, j, k;
	b=c/50;                 //b为50找零的张数
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

	cout << "共" << sum << "张找零，具体如下：" << endl;
	if(b!=0){
		cout << "50元 : " << b <<"张" << endl;
	}
	if (f != 0) {
		cout << "20元 : " << f << "张" << endl;
	}
	if (h != 0) {
		cout << "10元 : " << h << "张" << endl;
	}
	if (j != 0) {
		cout << "5元  : " << j << "张" << endl;
	}
	if (k != 0) {
		cout << "1元  : " << k << "张" << endl;
	}
	if (l != 0) {
		cout << "5角  : " << l << "张" << endl;
	}
	if (m != 0) {
		cout << "1角  : " << m << "张" << endl;
	}
	if (n != 0) {
		cout << "5分  : " << n << "张" << endl;
	}
	if (s != 0) {
		cout << "2分  : " << s << "张" << endl;
	}
	if (t != 0) {
		cout << "1分  : " << t << "张" << endl;
	}
	return 0;
}
