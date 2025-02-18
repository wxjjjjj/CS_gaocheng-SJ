#include <iostream>
#include <limits>//dev中必须加 vs可不加
#include<iomanip>
using namespace std;

int main()
{
	int a, b, c;//a是年，b是月,c是星期

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> a >> b;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃输入缓冲区中的字符，直到换行符!!加<windows.h>的头文件就不可用
			cout << "输入非法，请重新输入" << endl;
		}
		else {
			if ((a >= 2000 && a <= 2030 && b >= 1 && b <= 12) == 0) {
				cout << "输入非法，请重新输入" << endl;
			}
			else {
				while (1) {
					cout << "请输入" << a << "年" << b << "月1日的星期(0-6表示星期日-星期六) : ";
					cin >> c;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃输入缓冲区中的字符，直到换行符
						cout << "输入非法，请重新输入" << endl;
					}
					else {
						if ((c >= 0 && c <= 6) == 0) {
							cout << "输入非法，请重新输入" << endl;
						}
						else {
							break;
						}
					}
				}
				break;
			}
		}
	}
	

	cout << endl;
	cout << a << "年" << b << "月的月历为:" << endl;
	cout << "星期日  " << "星期一  " << "星期二  " << "星期三  " << "星期四  " << "星期五  " << "星期六  " << endl;
	int d = 1;
	switch (c) {
		case 0:
			cout << setw(4) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;
				
				if (d % 7 == 0) {
					cout << endl;
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//不是闰年
					    if (b == 2 && d == 28) {//2月
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					cout<<endl;
				    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
				    	if (b == 2 && d == 29) {//2月
					    	break;
				    	}
				    	else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
				    		break;
				    	}
				     	else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
					    	break;
				    	}
				    }
			    	else {//不是闰年
				    	if (b == 2 && d == 28) {//2月
				    		break;
				    	}
				    	else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
					    	break;
				    	}
				    	else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
					    	break;
					    }
			    	}
				    d++;
					cout << setw(4) << d;	
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				
			}
			break;

	}
	cout << endl;
	return 0;
}

