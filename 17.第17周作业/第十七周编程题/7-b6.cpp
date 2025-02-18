/* 2353761 王皙晶 计科 */
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
Date::Date(int y, int m, int d)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y >= 1900 && y <= 2099) {
		year = y;
	}
	else {
		year = 2000;
	}
	if (m >= 1 && m <= 12) {
		month = m;
	}
	else {
		month = 1;
	}
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
			if (d >= 1 && d <= 29) {
				day = d;
			}
			else {
				day = 1;
			}
		}
		else {
			if (d >= 1 && d <= 28) {
				day = d;
			}
			else {
				day = 1;
			}
		}
	}
	else {
		if (d >= 1 && d <= days[month - 1]) {
			day = d;
		}
		else {
			day = 1;
		}
	}
	return;
}
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int days)//从1900.1.1开始为第一天
{
	int i=0,every_month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	year = 1900;
	month = 1;
	day = 1;
	if (days >= 1) {
		while (1) {
			if (days > every_month_days[i % 12]) {
				if (((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) && i % 12 == 1) {   //真，则为闰年,二月有29天
					if (days > every_month_days[i % 12] + 1) {
						days = days - every_month_days[i % 12] - 1;
						i++;
					}
				}
				else {
					days = days - every_month_days[i % 12];
					i++;
				}
			}
			else {
				break;
			}
			if (i >= 12) {
				year++;
				i = 0;
			}
		}
		month = i + 1;
		day = days;
		if (year > 2099) {
			year = 2099;
			month = 12;
			day = 31;
		}
	}
}
void Date::set(int y, int m, int d)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y >= 1900 && y <= 2099) {
		year = y;
	}
	else {
		year = 2000;
	}
	if (m >= 1 && m <= 12) {
		month = m;
	}
	else {
		month = 1;
	}
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //真，则为闰年,二月有29天
			if (d >= 1 && d <= 29) {
				day = d;
			}
			else {
				day = 1;
			}
		}
		else {
			if (d >= 1 && d <= 28) {
				day = d;
			}
			else {
				day = 1;
			}
		}
	}
	else {
		if (d >= 1 && d <= days[month - 1]) {
			day = d;
		}
		else {
			day = 1;
		}
	}
	return;
}
void Date::set(int y, int m)
{
	if (y >= 1900 && y <= 2099) {
		year = y;
	}
	else {
		year = 2000;
	}
	if (m >= 1 && m <= 12) {
		month = m;
	}
	else {
		month = 1;
	}
	day = 1;
}
void Date::set(int y)
{
	if (y >= 1900 && y <= 2099) {
		year = y;
	}
	else {
		year = 2000;
	}
	month = 1;
	day = 1;
}
void Date::get(int& y, int& m, int& d)//引用
{
	y = year;
	m = month;
	d = day;
}
void Date::show()
{
	cout << year << '.' << month << '.' << day << endl;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
