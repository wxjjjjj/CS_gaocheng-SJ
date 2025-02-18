/*2353761 王皙晶 计科*/
#include<iostream>

using namespace std;

int main()
{
	char str[33] = { 0 };
	char* p;
	unsigned int count = 0, sum=0,tmp=1,a;

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.getline(str, 33);//读取了 n-1 个字符为止（为了留出空间存储字符串的结尾符 \0）。读取的文本（不包括换行符）会被存储在字符数组 str 中。

	p = str;
	while (*p != 0) {
		++p;
		++count;
	}//p指向尾0
	a = count;
	while (count != 0) {
		--p;
		for (int i = 1; i <=a-count; ++i) {
			tmp = tmp*2;
		}//2的n次方
		sum = sum+int(*p-'0') * tmp;
		--count;
		tmp = 1;
	}

	cout << sum << endl;
	return 0;

}