/*计科 王皙晶 2353761*/
#include<iostream>
#include <ctime> //随机数函数 

using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";

void generate_password(int changdu, int daxie, int xiaoxie, int number, int others, char password[17])
{
	
	int i,count=0;
	while (count<changdu) {
		i = rand() % 75 + 48; //控制i在48-122之间,是大写、小写、数字的范围
		
		if (i >= 48 && i <= 57&&number>0) {
			number--;
			password[count] = char(i);
			++count;
		}
		else if (i >= 65 && i <= 90 && daxie > 0) {
			daxie--;
			password[count] = char(i);
			count++;
		}
		else if (i >= 97 && i <= 122&&xiaoxie>0) {
			xiaoxie--;
			password[count] = char(i);
			count++;
		}
		else {
			if (others > 0) {
				others--;
				password[count] = other[i % 15];//防止越界
				count++;
			}
			else if(number==0&&daxie==0&&others==0&&xiaoxie==0) {//满足最小数量后随机
				if (i >= 48 && i <= 57) {
					password[count] = char(i);
					++count;
				}
				else if (i >= 65 && i <= 90) {
					password[count] = char(i);
					count++;
				}
				else if (i >= 97 && i <= 122) {
					password[count] = char(i);
					count++;
				}
				else {
					password[count] = other[i % 15];//防止越界
					count++;
				}
			}
		}//先满足每种类型符号的最小数量限制

	}

	return;
}


int main()
{
	char password[10][17] = { 0 };//char 0是尾零，‘0’是数字0，'/0'是尾零,最后一行存尾0
	/* srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可
	必须在main函数里执行哈，放在函数里不行*/
	srand((unsigned int)(time(0)));

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int changdu, daxie, xiaoxie, number, others;
	cin >> changdu;
	if (cin.good() == 0) {
		cout << "输入非法" << endl;
		return 0;
	}
	else {
		if (changdu >= 12 && changdu <= 16) {
			cin >> daxie;
			if (cin.good() == 0) {
				cout << "输入非法" << endl;
				return 0;
			}
			else {
				if (daxie >= 2) {
					cin >> xiaoxie;
					if (cin.good() == 0) {
						cout << "输入非法" << endl;
					}
					else {
						if (xiaoxie >= 2) {
							cin >> number;
							if (cin.good() == 0) {
								cout << "输入非法" << endl;
							}
							else {
								if (number >= 2) {
									cin >> others;
									if (cin.good() == 0) {
										cout << "输入非法" << endl;
									}
									else {
										if (others >= 2) {
											if (others + number + daxie + xiaoxie > changdu) {
												cout << "所有字符类型之和[" << daxie << '+' << xiaoxie << '+' << number << '+' <<others << "]大于总密码长度[" << changdu << "]" << endl;
											}
											else {//输入处理完成，开始生成随机十组密码
												for (int i = 0; i < 10; ++i) {
													generate_password(changdu,daxie, xiaoxie,number,others,password[i]);
												}
												cout << changdu << ' ' << daxie << ' ' << xiaoxie << ' ' << number << ' ' << others << endl;
												for (int i = 0; i < 10; ++i) {
													cout << password[i] << endl;
												}
												return 0;
											}
										}
										else {
											cout << "其它符号个数[" << others << "]不正确" << endl;
										}
									}
								}
								else {
									cout << "数字个数[" << number << "]不正确" << endl;
								}
							}
						}
						else {
							cout<< "小写字母个数[" << xiaoxie << "]不正确" << endl;
						}
					}
				}
				else {
					cout << "大写字母个数[" << daxie << "]不正确" << endl;
				}
			}
		}
		else {
			cout << "密码长度[" << changdu << "]不正确" << endl;
		}
		
	}
	return 0;
}
