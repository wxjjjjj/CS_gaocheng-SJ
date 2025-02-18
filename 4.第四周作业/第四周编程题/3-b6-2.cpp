#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double a, d, x;
	int e, f, g, h, i, j, k, l, m, n, p, q;
	cin >> a;
	a = a + 0.005;                              //弥补实数误差，如果是三位小数就要更小-0.0005，以此类推
	long c;                                     //因为long long在dev中编译不通过，必须用long型
	x = a / 100;								    //将可能溢出的数据变得不溢出（最多11变9位，包不溢出） （此时两位小数变四位小数）
	c = long(x);									//将浮点数的整数部分存在c中
	d = x - c;								    //将小数部分存在d中

	g = c % 10;									//百位数字
	c = c / 10;
	h = c % 10;									//千位数字
	c = c / 10;
	i = c % 10;									//万位数字
	c = c / 10;
	j = c % 10;									//十万位数字
	c = c / 10;
	k = c % 10;									//百万位数字
	c = c / 10;
	l = c % 10;									//千万位数字
	c = c / 10;
	m = c % 10;									//亿位数字
	c = c / 10;
	n = c % 10;									//十亿位数字

	p = int(d * 10);                            //十位数字
	q = int((d - p * 0.1) / 0.01);              //圆位数字
	e = int((d - 0.1 * p - 0.01 * q) / 0.001);									//角位数字
	f = int((d - 0.1 * p - 0.01 * q - 0.001 * e) / 0.0001);									//分位数字

	cout << "大写结果是:" << endl;

	switch (n) {
		case 0:
			break;
		case 1:
			if (m == 0) {
				cout << "壹拾亿";
			}
			else {
				cout << "壹拾";
			}
			break;
		case 2:
			if (m == 0) {
				cout << "贰拾亿";
			}
			else {
				cout << "贰拾";
			}
			break;
		case 3:
			if (m == 0) {
				cout << "叁拾亿";
			}
			else {
				cout << "叁拾";
			}
			break;
		case 4:
			if (m == 0) {
				cout << "肆拾亿";
			}
			else {
				cout << "肆拾";
			}
			break;
		case 5:
			if (m == 0) {
				cout << "伍拾亿";
			}
			else {
				cout << "伍拾";
			}
			break;
		case 6:
			if (m == 0) {
				cout << "陆拾亿";
			}
			else {
				cout << "陆拾";
			}
			break;
		case 7:
			if (m == 0) {
				cout << "柒拾亿";
			}
			else {
				cout << "柒拾";
			}
			break;
		case 8:
			if (m == 0) {
				cout << "捌拾亿";
			}
			else {
				cout << "捌拾";
			}
			break;
		case 9:
			if (m == 0) {
				cout << "玖拾亿";
			}
			else {
				cout << "玖拾";
			}
			break;
	}
	switch (m) {
		case 0:
			break;
		case 1:
			cout << "壹亿";
			break;
		case 2:
			cout << "贰亿";
			break;
		case 3:
			cout << "叁亿";
			break;
		case 4:
			cout << "肆亿";
			break;
		case 5:
			cout << "伍亿";
			break;
		case 6:
			cout << "陆亿";
			break;
		case 7:
			cout << "柒亿";
			break;
		case 8:
			cout << "捌亿";
			break;
		case 9:
			cout << "玖亿";
			break;
	}                                                     //亿和十亿位处理完成

	switch (l) {
		case 0:
			if(l==0&&k==0&&j==0&&i==0){
				break;
			}
			else if (m == 0 && n == 0) {
				break;
			}
			else {
				cout << "零";
				break;
			}
		case 1:
			cout << "壹仟";
			break;
		case 2:
			cout << "贰仟";
			break;
		case 3:
			cout << "叁仟";
			break;
		case 4:
			cout << "肆仟";
			break;
		case 5:
			cout << "伍仟";
			break;
		case 6:
			cout << "陆仟";
			break;
		case 7:
			cout << "柒仟";
			break;
		case 8:
			cout << "捌仟";
			break;
		case 9:
			cout << "玖仟";
			break;
	}
	switch (k) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (m == 0 && n == 0 && l == 0) {
				break;
			}
			else{
				if (l == 0) {
					break;
				}
				else if(l!=0&&j!=0&&i!=0){
					cout << "零";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "壹佰";
			break;
		case 2:
			cout << "贰佰";
			break;
		case 3:
			cout << "叁佰";
			break;
		case 4:
			cout << "肆佰";
			break;
		case 5:
			cout << "伍佰";
			break;
		case 6:
			cout << "陆佰";
			break;
		case 7:
			cout << "柒佰";
			break;
		case 8:
			cout << "捌佰";
			break;
		case 9:
			cout << "玖佰";
			break;
	}
	switch (j) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (l == 0 && k == 0 && m == 0 && n == 0) {
				break;
			}
			else{
				if ( k != 0&&i!=0){
					cout << "零";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "壹拾";
			break;
		case 2:
			cout << "贰拾";
			break;
		case 3:
			cout << "叁拾";
			break;
		case 4:
			cout << "肆拾";
			break;
		case 5:
			cout << "伍拾";
			break;
		case 6:
			cout << "陆拾";
			break;
		case 7:
			cout << "柒拾";
			break;
		case 8:
			cout << "捌拾";
			break;
		case 9:
			cout << "玖拾";
			break;
	}
	switch (i) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0) {
				break;
			}
			else{
				cout << "万";
				break;
			}
		case 1:
			cout << "壹万";
			break;
		case 2:
			cout << "贰万";
			break;
		case 3:
			cout << "叁万";
			break;
		case 4:
			cout << "肆万";
			break;
		case 5:
			cout << "伍万";
			break;
		case 6:
			cout << "陆万";
			break;
		case 7:
			cout << "柒万";
			break;
		case 8:
			cout << "捌万";
			break;
		case 9:
			cout << "玖万";
			break;
	}                        //千万、百万、十万、万处理完成

	switch (h) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0&&i==0) {
				break;
			}
			else if (g == 0 && p == 0) {
				break;
			}
			else  {
				cout << "零";
				break;
			}
		case 1:
			cout << "壹仟";
			break;
		case 2:
			cout << "贰仟";
			break;
		case 3:
			cout << "叁仟";
			break;
		case 4:
			cout << "肆仟";
			break;
		case 5:
			cout << "伍仟";
			break;
		case 6:
			cout << "陆仟";
			break;
		case 7:
			cout << "柒仟";
			break;
		case 8:
			cout << "捌仟";
			break;
		case 9:
			cout << "玖仟";
			break;
	}
	switch (g) {
		case 0:
			if (h== 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0&&h==0) {
				break;
			}
			else {
				if (h == 0) {
					break;
				}
				else if(h!=0&&p!=0){
					cout << "零";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "壹佰";
			break;
		case 2:
			cout << "贰佰";
			break;
		case 3:
			cout << "叁佰";
			break;
		case 4:
			cout << "肆佰";
			break;
		case 5:
			cout << "伍佰";
			break;
		case 6:
			cout << "陆佰";
			break;
		case 7:
			cout << "柒佰";
			break;
		case 8:
			cout << "捌佰";
			break;
		case 9:
			cout << "玖佰";
			break;
	}
	switch (p) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0&&g==0) {
				break;
			}
			else {
				if (q!= 0 &&g!=0){
					cout << "零";
					break;
				}
				else if (g ==0 && q != 0) {
					cout << "零";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "壹拾";
			break;
		case 2:
			cout << "贰拾";
			break;
		case 3:
			cout << "叁拾";
			break;
		case 4:
			cout << "肆拾";
			break;
		case 5:
			cout << "伍拾";
			break;
		case 6:
			cout << "陆拾";
			break;
		case 7:
			cout << "柒拾";
			break;
		case 8:
			cout << "捌拾";
			break;
		case 9:
			cout << "玖拾";
			break;
	}
	switch (q) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0 ) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0&&p==0){
				cout << "零圆";
				break;
			}
			
			else {
				cout << "圆";
				break;
			}
		case 1:
			cout << "壹圆";
			break;
		case 2:
			cout << "贰圆";
			break;
		case 3:
			cout << "叁圆";
			break;
		case 4:
			cout << "肆圆";
			break;
		case 5:
			cout << "伍圆";
			break;
		case 6:
			cout << "陆圆";
			break;
		case 7:
			cout << "柒圆";
			break;
		case 8:
			cout << "捌圆";
			break;
		case 9:
			cout << "玖圆";
			break;
	}                        //千、百、十、圆处理完成

	if (e == 0 && f == 0) {
		cout << "整" << endl;
	}
	else if (e == 0 && f != 0) {
		if (q != 0||p!=0||g!=0||h!=0||i!=0||j!=0||k!=0||l!=0||m!=0||n!=0){
			cout << "零";
		}
		switch (f) {
			case 1:
				cout << "壹分" << endl;
				break;
			case 2:
				cout << "贰分" << endl;
				break;
			case 3:
				cout << "叁分" << endl;
				break;
			case 4:
				cout << "肆分" << endl;
				break;
			case 5:
				cout << "伍分" << endl;
				break;
			case 6:
				cout << "陆分" << endl;
				break;
			case 7:
				cout << "柒分" << endl;
				break;
			case 8:
				cout << "捌分" << endl;
				break;
			case 9:
				cout << "玖分" << endl;
				break;
		}
	}
	else if (e != 0 && f == 0) {
		switch (e) {
			case 1:
				cout << "壹角整" << endl;
				break;
			case 2:
				cout << "贰角整" << endl;
				break;
			case 3:
				cout << "叁角整" << endl;
				break;
			case 4:
				cout << "肆角整" << endl;
				break;
			case 5:
				cout << "伍角整" << endl;
				break;
			case 6:
				cout << "陆角整" << endl;
				break;
			case 7:
				cout << "柒角整" << endl;
				break;
			case 8:
				cout << "捌角整" << endl;
				break;
			case 9:
				cout << "玖角整" << endl;
				break;
		}
	}
	else {
		switch (e) {
			case 1:
				cout << "壹角";
				break;
			case 2:
				cout << "贰角";
				break;
			case 3:
				cout << "叁角";
				break;
			case 4:
				cout << "肆角";
				break;
			case 5:
				cout << "伍角";
				break;
			case 6:
				cout << "陆角";
				break;
			case 7:
				cout << "柒角";
				break;
			case 8:
				cout << "捌角";
				break;
			case 9:
				cout << "玖角";
				break;
		}
		switch (f) {
			case 1:
				cout << "壹分" << endl;
				break;
			case 2:
				cout << "贰分" << endl;
				break;
			case 3:
				cout << "叁分" << endl;
				break;
			case 4:
				cout << "肆分" << endl;
				break;
			case 5:
				cout << "伍分" << endl;
				break;
			case 6:
				cout << "陆分" << endl;
				break;
			case 7:
				cout << "柒分" << endl;
				break;
			case 8:
				cout << "捌分" << endl;
				break;
			case 9:
				cout << "玖分"<<endl;
				break;
		}
	}
	return 0;
}