/* 计科 2353761 王皙晶 */
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		while (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 丢弃输入缓冲区中的字符，直到换行符
			cout << "请输入x的值[0-100] : ";
			cin >> x;
		}

		if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.good()=" << cin.good() <<  " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}
