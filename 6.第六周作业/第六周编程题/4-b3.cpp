#include <iostream>
#include <limits> //dev中必须加 vs可不加 因为cin.ignore(numeric_limits<streamsize>::max(), '\n');
#include<iomanip>
using namespace std;



int zeller(int y, int m, int d) //已经定义了y，m，d函数内不用再定义
{
	int c, w, q;
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
	return w;    //w为给定年月日对应的星期0代表周天
}

void calendar(int year, int month)
{

	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	int l;
	l = zeller(year, month, 1);  //a年b月第一天的星期;

	int d = 1;
	
	switch (l) {
		case 0:
			cout << setw(4) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 0) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}


				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 1:
			cout << setw(12) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 6) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 2:
			cout << setw(20) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;


				if (d % 7 == 5) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}


				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 3:
			cout << setw(28) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 4) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
			break;
		case 4:
			cout << setw(36) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 3) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}
				
			    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 5:
			cout << setw(44) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 2) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}

			}
		break;
		
		case 6:
			cout << setw(52) << d << endl;
			for (d = 2; d <= 31; d++) { //每一次加之前都必须判断是否到了这个月的最后一天！！！！！！！！ 

				if (d == 2) {
					cout << setw(4) << d;
					d++;
				}
				cout << setw(8) << d;

				if (d % 7 == 1) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
						if (month == 2 && d == 29) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//不是闰年
						if (month == 2 && d == 28) {//2月
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年
					if (month == 2 && d == 29) {//2月
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//不是闰年
					if (month == 2 && d == 28) {//2月
				    	cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;

	}
	      //cout<<endl; 逻辑有点问题，因为换行的情况是 到达这月的最后一天or被7除余x (已经改好 
	cout << "======================================================" << endl;
}

int main()
{
	int a, b;//a是年，b是月

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> a >> b;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃输入缓冲区中的字符，直到换行符!!加<windows.h>的头文件就不可用--<limits>
			cout << "输入错误，请重新输入" << endl;
		}
		else {
			if (a < 1900 || a>2100) {
				cout << "年份不正确，请重新输入" << endl;
			}
			else {
				if (b > 12 || b < 1) {
					cout << "月份不正确，请重新输入" << endl;
				}
				else {
					break;
				}

			}
		}
	}
	cout << endl;
	calendar(a, b);

	return 0;
}
