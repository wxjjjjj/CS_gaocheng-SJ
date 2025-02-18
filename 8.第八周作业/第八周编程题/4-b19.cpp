/*王皙晶 2353761 计科*/
#include<iostream>
using namespace std;

int min(int a, int b,int c=2147483647,int d=2147483647) {//更好的写法是INT_MAX要加#include<limitis.h>头文件宏定义or记十六进制表示0x7FFFFFFF，然后十进制（默认输出显示）输出即可 
	int x = a < b ? a : b;
	int y = x < c ? x : c;
	return y < d ? y : d;
}



int main() {

	int n, a, b, c, d, x;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			if (n >= 2 && n <= 4) {
				if (n == 2) {
					cin >> a >> b;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0) {
							x = min(a, b);
							cout << "min=" << x << endl;
							break;
						}
					}
				}
				else if (n == 3) {
					cin >> a >> b >> c;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0 && c > 0) {
							x = min(a, b, c);
							cout << "min=" << x << endl;
							break;
						}
					}
				}
				else {
					cin >> a >> b >> c >> d;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0 && c > 0 && d > 0) {
							x = min(a, b, c, d);
							cout << "min=" << x << endl;
							break;
						}
					}
				}
			}
			else {
				cout << "个数输入错误" << endl;
				break;
			}
		}
	}

	return 0;
}
