/* 2353761 王皙晶 计科 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	cin.getline(str, 256);//读入字符串

	pnum = a;
	pa = a;
	p = str;
	is_num = 0;
	for (; *p != 0 && pnum - pa < N; ++p) {
		if ('0' <= *p &&*p<= '9') {

			if (!is_num) {
				*pnum = int(*p - '0');
				is_num = 1;
			}
			else {
				*pnum = *pnum * 10 + int(*p - '0');
			}
		}
		else {
			if (is_num) {
				is_num = 0;
				pnum++;
			}
		}
	}

	cout << "共有" << pnum - pa + is_num << "个整数" << endl;
	for (; pnum-pa+is_num!= 0; ++pa) {
		cout << *pa << ' ';
	}
	cout << endl;

	return 0;
}
