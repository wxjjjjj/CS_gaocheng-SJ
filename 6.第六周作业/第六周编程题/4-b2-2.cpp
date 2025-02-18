#include <iostream>
#include <limits> //dev中必须加 vs可不加
using namespace std;



int zeller(int y, int m, int d) //已经定义了y，m，d函数内不用再定义
{
	int c,w,q;
	q = y;    //年份存在q内不动
	c = y / 100;
	y = y - c * 100;
	if (m == 1) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 13;
	}
	else if (m == 2) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 14;
	}
	else {
		m = m;
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w = w + 7;
	}
	w = w % 7;
	return w;
}

int main()
{
	int a, b, c,l;//a是年，b是月,c是星期

	while (1) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> a >> b>>c;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃输入缓冲区中的字符，直到换行符!!加<windows.h>的头文件就不可用
			cout << "输入错误，请重新输入" << endl;
		}
		else {
			if (a<1900||a>2100) {
				cout << "年份不正确，请重新输入" << endl;
			}
			else {
				if (b > 12 || b < 1) {
					cout << "月份不正确，请重新输入" << endl;
				}
				else {  //看日的正确性
					if (b == 2) {
						if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {  //闰年二月
							if (c >= 0 && c <= 29) {
								break;
							}
							else {
								cout << "日不正确，请重新输入" << endl;
							}
						}
						else {
							if (c >= 0 && c <= 28) {
								break;
							}
							else {
								cout << "日不正确，请重新输入" << endl;
							}
						}
					}
					else if (b==1||b==3||b==5||b==7||b==8||b==10||b==12) {
						if (c >= 0 && c <= 31) {
							break;
						}
						else {
							cout << "日不正确，请重新输入" << endl;
						}

					}
					else {
						if (c >= 0 && c <= 30) {
							break;
						}
						else {
							cout << "日不正确，请重新输入" << endl;
						}
					}
				}
			}
		}
	}
	l = zeller(a, b, c);
	switch (l) {
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
		case 0:
			cout << "星期日" << endl;
			break;
		default:
			break;
	}
	return 0;
}
