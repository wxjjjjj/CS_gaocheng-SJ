#include<iostream>
#include<cmath>

using namespace std;

//printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, sum);

void mingci(int array[], int n) {
	//先排序，最高的成绩在第a[0]个
	int i, j, k, t, mingci = 0;
	for (i = 0; i < n - 1; ++i) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] > array[k]) {
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}

	//排名
	cout << array[0] << ' '<<1<<endl;
	for (i = 1; i < n; ++i) {
		if (array[i] >= 0) {
			for (j = i-1; j >=0; j--) {
				if (array[j] == array[i]) {
					mingci = j + 1;
				}
			}
			if (mingci == 0) {
				mingci = i + 1;
			}
			cout << array[i] << ' ' << mingci << endl;;
			mingci = 0;
		}
	}
}

int main() {
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;;
	int a[1000], i;           //自动变量数组未初始化，其值不确定；只有全局变量不初始化时默认为0

	for (i = 0; i < 1000; ++i) {  //初始化
		a[i] = -1;
	}

	for (i = 0; i < 1000; ++i) {  //i有记录有效读入数组中数据个数的作用，正确读入了i+1个
		cin >> a[i];
		if (a[i] < 0) {
			break;
		}
	}
	if (a[0] < 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "输入的数组为:" << endl;
	for (i = 0; i < 1000; ++i) {
		if (a[i] >= 0) {
			cout << a[i] << ' ';
			if (i % 10 == 9) {
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "分数与名次的对应关系为:" << endl;

	mingci(a, 1000);

	return 0;
}