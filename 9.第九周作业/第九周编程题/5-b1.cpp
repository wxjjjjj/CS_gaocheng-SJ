#include<iostream>
#include<cmath>

using namespace std;

void paixu(int array[], int n) {
	int i,j,k,t;
	for (i = 0; i < n-1; ++i) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] < array[k]) {
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
	for (i = 0; i < n; ++i) {
		if (array[i] > 0)
			cout << array[i] << ' ';
	}
}

int main() {
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int a[21], i, b;           //自动变量数组未初始化，其值不确定；只有全局变量不初始化时默认为0

	for (i = 0; i < 20; ++i) {  //初始化
		a[i] = 0;
	}

	for (i = 0; i < 20; ++i) {  //i有记录有效读入数组中数据个数的作用，正确读入了i+1个
		cin >> a[i];
		if (a[i] <= 0) {
			break;              
		}
	}
	if (a[0] <= 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (i = 0; i <20; ++i) {
		if(a[i]>0)
			cout << a[i] << ' ';
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;

	cin.ignore(65536, '\n');        //这个在输入前再清空吧，如果cin后不cout直接ignore，则后续再cout就什么都没有

	cin >> a[20];
	cout << "插入后的数组为：" << endl;
	paixu(a, 21);
	cout << endl;
	return 0;
}