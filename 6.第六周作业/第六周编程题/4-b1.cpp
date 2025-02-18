/* 2353761 王皙晶 计科 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：int num,int flag_of_zero
  返 回 值：void
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考-
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
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
	//开始处理十亿位n
	daxie(n, 0);
	if (n != 0) {
		cout << "拾";
	}
	//开始处理亿m
	daxie(m, 0);
	if (n+m) {
		cout << "亿";  //十亿，亿位上不会出现“零”
	}
	
	//开始处理千万l，百万k，十万j，万i
	daxie(l, k>0&&n+m>0);
	if (l != 0) {
		cout << "仟";
	}
	daxie(k, j>0&&n+m+l>0);
	if (k != 0) {
		cout << "佰";
	}
	daxie(j, i>0&&n+m+l+k>0);
	if (j != 0) {
		cout << "拾";
	}
	daxie(i, 0);
	if (l != 0 || k != 0 || j != 0 || i != 0) {
		cout << "万";
	}
	//仟h，佰g，拾p，圆q
	daxie(h, g > 0 && n + m + l + k +j+i> 0);
	if (h != 0) {
		cout << "仟";
	}
	daxie(g, p > 0 && n + m + l + k + j + i+h > 0);
	if (g != 0) {
		cout << "佰";
	}
	daxie(p, q > 0 && n + m + l + k + j + i + h+g > 0);
	if (p != 0) {
		cout << "拾";
	}
	daxie(q, n + m + l + k + j + i + h + g+p+q+e+f==0);
	if (n + m + l + k + j + i + h + g+p+q==0&&(e!=0||f!=0)) {	
	}
	else{
		cout << "圆";
	}
	//角e，分f；
	if (e == 0 && f == 0) {
		cout << "整";
	}
	else if (e!=0&&f==0){
		daxie(e, 0);
		cout << "角整";
	}
	else if (e==0&&f!=0){
		daxie(e,n + m + l + k + j + i + h + g+p+q>0);
		daxie(f, e);
		cout << "分";
	
	}
	else {
		daxie(e, 0);
		if (e != 0) {
			cout << "角";
		}
		daxie(f, 0);
		if (f != 0) {
			cout << "分";
		}
	}
	cout << endl;
	return 0;
}




















