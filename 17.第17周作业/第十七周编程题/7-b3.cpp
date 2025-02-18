/* 2353761 王皙晶 计科 */
#include <iostream>
using namespace std;

/* 1、不允许定义任何类型的全局变量，包括常变量及宏定义等
   2、不允许给出任何形式的全局函数
*/

/* --- 将类的定义补充完整 --- */
class Days {
private:
	int year;
	int month;
	int day;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员

	/* 下面可以补充需要的类成员函数的定义（不提供给外界，仅供本类的其它成员函数调用，因此声明为私有，数量不限，允许不定义） */

public:
	Days(int year, int month,int day);
	int calc_days();     //计算是当年的第几天

	/* 下面可以补充其它需要的类成员函数的定义(体外实现)，数量不限，允许不定义 */

};

/* --- 此处给出类成员函数的体外实现 --- */
int Days::calc_days()
{
	int d=0;
	switch (month) {
		case 1:
			if (day>= 0 && day <= 31) {
				d = day;
			}
			else {
				d = -1;
			}
			break;
		case 2:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 29 && day >= 0) {
					d = 31 + day;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 28 && day >= 0) {
					d = 31 + day;
				}
				else {
					d = -1;
				}
				break;
			}
		case 3:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28;
				}
				else {
					d = -1;
				}
				break;
			}
		case 4:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 5:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 6:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + 31 + day + 28 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 7:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 8:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 9:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 10:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 11:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 12:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		default:
			cout << "输入错误-月份不正确" << endl;
			break;
	}
	return d;
}
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);//数据成员是私有，所以不能直接用这样的方法初始化
		cout << "应该输出78， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "应该输出77， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "应该输出366，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "应该输出365，实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "应该输出60， 实际是：" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "应该输出-1， 实际是：" << d1.calc_days() << endl;
	}

	return 0;
}
