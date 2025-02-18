#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


/*
另一种方法：
数组元素的值做另一个数组的下标--但有越界的风险*/

void count(int array[],int n) {
	//先排序，最高的成绩在第a[0]个
	int i, j, k, t,geshu=0;
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
	for (i = 0; i < n; ++i) {
		if (array[i] >= 0) {
			for (j = i+1; j < n; j++) {
				if (array[j] == array[i]) {
					array[j] = -1;
					++geshu;
				}
			}
			if (geshu >= 0) {
				++geshu;
				printf("%d ", array[i]);
				printf("%d\n", geshu);
			}
			geshu = 0;
		}
			
	}
}

int main() {
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int a[1000], i;           //自动变量数组未初始化，其值不确定；只有全局变量不初始化时默认为0

	for (i = 0; i < 1000; ++i) {  //初始化
		a[i] = -1;
	}

	for (i = 0; i < 1000; ++i) {  //i有记录有效读入数组中数据个数的作用，正确读入了i+1个
		scanf("%d", &a[i]);    
		if (a[i] < 0) {
			break;
		}
	}
	if (a[0] < 0) {
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:\n");
	for (i = 0; i < 1000; ++i) {
		if (a[i] >= 0) {
			printf("%d ", a[i]);
			if (i % 10 == 9) {
				printf("\n");
			}
		}
	}
	printf("\n");
	printf("分数与人数的对应关系为:\n");

	count(a,1000);

	return 0;
}
