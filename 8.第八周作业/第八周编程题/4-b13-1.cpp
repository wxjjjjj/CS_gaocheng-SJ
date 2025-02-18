/* 2353761 王皙晶 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
            3、允许定义一个静态局部变量
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int count = 0;
	if (n == 1) {
		++count;
		cout <<setw(5)<<count<<':'<< setw(3) << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++count;
	cout << setw(5) << count <<':'<< setw(3) << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int layers;
	char src, dst, tmp;//layers是层，src是起始柱,dst是目标柱,tmp是辅助柱

	while (1) {
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> layers;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
		}
		else {
			cin.ignore(65536, '\n');//输入正确也要忽略后面的字符
			if (layers >= 1 && layers <= 16) {
				while (1) {
					cout << "请输入起始柱(A-C)" << endl;
					cin >> src;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
					}
					else {
						cin.ignore(65536, '\n');//输入正确也要忽略后面的字符
						if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
							while (1) {
								cout << "请输入目标柱(A-C)" << endl;
								cin >> dst;
								if (cin.good() == 0) {
									cin.clear();
									cin.ignore(65536, '\n'); // 丢弃输入缓冲区中的字符，直到换行符
								}
								else {
									cin.ignore(65536, '\n');
									if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
										if (src == dst || src == dst + 32 || src == dst - 32) {
											if (src >= 'a' && src <= 'c') {
	                                        	src = src - 32;
	                                        }
	                                        if (dst >= 'a' && dst <= 'c') {
	                                        	dst = dst - 32;
	                                        }
											cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
										}
										else {
											break;
										}
									}

								}
							}
							break;
						}
					}
				}
				break;
			}
		}
	}                //输入部分处理完毕

	cout << "移动步骤为:" << endl;
	if (src >= 'a' && src <= 'c') {
		src = src - 32;
	}
	if (dst >= 'a' && dst <= 'c') {
		dst = dst - 32;
	}
	if ((src == 'A' || src == 'B') && (dst == 'A' || dst == 'B')) {
		tmp = 'C';
	}
	else if ((src == 'A' || src == 'C') && (dst == 'A' || dst == 'C')) {
		tmp = 'B';
	}
	else {
		tmp = 'A';
	}
	hanoi(layers, src, tmp, dst);

	return 0;
}
