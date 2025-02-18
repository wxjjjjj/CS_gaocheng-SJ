#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
	cout << "请输入x的值[-10 ~ +65]" << endl;
	int x;
	cin >> x;
	while (cin.good() == 1 && (x > 65 || x < -10)) {
		cout << "输入非法，请重新输入" << endl;
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
	}
	double sum = 0;
	int i;
	double c,a,b;
	c = 1;
	a = 1;
	b = 1;
	for (i = 1; fabs(c) >= 1e-6; ++i) {
		sum = sum + c;			//e^x  先判断再加，就能确保加的最后一项真的大于等于1e-6 
		a = x * a/10;				//x^n
		b = b * i/10;				//n!
		c = a / b;				//x^n/n!

	}
	cout<<"e^"<<x<<"="<< setprecision(10) << sum << endl;

	return 0;
}
