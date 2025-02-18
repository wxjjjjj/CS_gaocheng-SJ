/*王皙晶 2353761 计科*/
#include<iostream>

using namespace std;
#define num 9     //!!!!!宏定义后面没有分号！！！const才有
#define MAX 65536

void examine_xiaojiugongge(int array[9][9],int array2[9], int row,int column) 
{//column列，row行
	int k;
	for (int i = row; i < row+3; ++i) {
		for (int j = column; j < column+3; ++j) {
			k = array[i][j];
			++array2[k - 1];
		}
	}//一个小九宫格遍历完
	for (int l = 0; l < num; ++l) {
		if (array2[l] != 1) {
			cout << "不是数独的解" << endl;
			return;
		}
	}//一个小九宫格判断完
	for (int d = 0; d < num; ++d) {
		array2[d] = 0;
	}//计数数组归零
	return;
}

int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int a[num][num] = { 0 };
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			while (1){
				cin >> a[i][j];           //注意！！！cin希望赋值的是单个变量，所以cin>>a[i]一整列是错的
				if (cin.good() == 0) {
					cin.clear();
					cin.ignore(MAX, '\n');
					cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
					continue;
				}
				else {
					if (a[i][j] >= 1 && a[i][j] <= 9) {
						break;
					}
					else {
						cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
						continue;
					}
				}
			}
		}	
	}                  //输入处理完成

	int k = 0, b[9] = { 0 };//b[j]的值代表数字j+1出现的次数
	//每一行检查
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			k = a[i][j];
			++b[k - 1];
		} //一行统计完
		for (int l = 0; l < num; ++l) {
			if (b[l] != 1) {
				cout << "不是数独的解" << endl;
				return 0;
			}
		}//一行判断完
		for (int d = 0; d < num; ++d) {
			b[d] = 0;
		}//计数数组归零，下一行统计
	}
	//每一列检查
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			k = a[j][i];
			++b[k - 1];
		} //一列统计完
		for (int l = 0; l < num; ++l) {
			if (b[l] != 1) {
				cout << "不是数独的解" << endl;
				return 0;
			}
		}//一列判断完
		for (int d = 0; d < num; ++d) {
			b[d] = 0;
		}//计数数组归零，下一列统计
	}
	//每个小九宫格检查
	examine_xiaojiugongge(a, b, 0, 0);//column列，row行	
	examine_xiaojiugongge(a, b, 0, 3);
	examine_xiaojiugongge(a, b, 0, 6);
	examine_xiaojiugongge(a, b, 3, 0);
	examine_xiaojiugongge(a, b, 3, 3);
	examine_xiaojiugongge(a, b, 3, 6);
	examine_xiaojiugongge(a, b, 6, 0);
	examine_xiaojiugongge(a, b, 6, 3);
	examine_xiaojiugongge(a, b, 6, 6);

	cout << "是数独的解" << endl;
	
	return 0;
}
