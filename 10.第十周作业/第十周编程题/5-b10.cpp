/*2353761 王皙晶 计科*/
#include <iostream>
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

void print_title(int month)//打印日历框架
{
	cout << setiosflags(ios::right)<<setw(3*4+1) << month - 2 << "月";
	cout << setiosflags(ios::right)<< setw(7*4+2) << month - 1 << "月";
	cout << setiosflags(ios::right)<< setw(7 * 4 + 2) << month << "月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	return;
}
 
void print_days(int year, int month3, int array[])   //逐行打印年历 array是每个月的天数数组
{
	int k = 0,w = 0,tmp=0,max_line=0,line=0;
	int a[6] = { 0 };//这个数组的作用是：a[0]-a[1]存month3-2月的k-行数、w-该月第一天的星期数（0为周日）···以此类推
	for (int i = month3 - 2; i <= month3; ++i) {
		w=zeller(year, i, 1);
		a[tmp+1] = w;
		
		for (int k = 1; k <= 6; ++k) {
			if (7 * k - w >= array[i-1]) {
				a[tmp] = k;
				break;
			}
		}
		tmp = tmp + 2;
	}
	if (a[0] > a[2]) {
		max_line = a[0];
	}
	else {
		max_line = a[2];
	}
	if (max_line > a[4]) {
		max_line = max_line;
	}
	else {
		max_line = a[4];
	}
	
	
	cout << resetiosflags(ios::right);                                         //!!如果想要right对齐后再left对齐，需要在两者之间加入一句这个！！

	for (int c = 1; c <= 5; c = c + 2) { //第一行打印完毕
		
		switch (a[c]) {
			case 0:
				cout <<  setiosflags(ios::left)<<setw(4)  << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 1:
				cout << setw(4 * 1) << setfill(' ') << ' ';
				cout << setiosflags(ios::left) << setw(4)  << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setiosflags(ios::left) << setw(4) << i;
				}
				break;
			case 2:
				cout << setw(4 * 2) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 3:
				cout << setw(4 * 3) << setfill(' ') << ' ';
				cout <<setiosflags(ios::left) <<setw(4) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setiosflags(ios::left) << setw(4) << i;
				}
				break;
			case 4:
				cout << setw(4 * 4) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 5:
				cout << setw(4 * 5) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 6:
				cout << setw(4 * 6) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			default:
				break;
		}
		cout << setw(4) << setfill(' ')<<' ';
	}
	cout << endl;
	for (line = 2; line <= max_line; ++line) {//之后的几行
		for (int c = 1; c <= 5; c = c + 2) {//每一部分
			for (int i = 7 * (line - 1) - a[c]+1; i <= 7 * line - a[c];++i) {
				if (i <= array[month3 - 3 + (c / 2)]) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				else {
					cout << setw(4) << setfill(' ') << ' ';
				}
				if (i == 7 * line - a[c]) {
					break;
				}
			}
			cout << setw(4) << setfill(' ') << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main()
{
	int meigeyue[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//每个月的天数
	int year = 0, month = 0, day = 0;

	cout << "请输入年份[1900-2100]" << endl;
	cin >> year;
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//闰年-2月有29天
		++meigeyue[1];
	}
	cout << year << "年的日历:" << endl;
	cout << endl;
	print_title(3);
	print_days(year, 3, meigeyue);
	print_title(6);
	print_days(year, 6, meigeyue);
	print_title(9);
	print_days(year, 9, meigeyue);
	print_title(12);
	print_days(year, 12, meigeyue);
	
	cout<<endl; 
	
	return 0;
}
