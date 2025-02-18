/* 计科 王皙晶 2353761 */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<string.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */     //chnstr中每两个一个汉字
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void danwei_function(int n)
{
	switch (n) {
		case 0:
			strcat(result, "拾");
			break;
		case 1:
			strcat(result, "亿");
			break;
		case 2:
			strcat(result, "仟");
			break;
		case 3:
			strcat(result, "佰");
			break;
		case 4:
			strcat(result, "拾");
			break;
		case 5:
			strcat(result, "万");
			break;
		case 6:
			strcat(result, "仟");
			break;
		case 7:
			strcat(result, "佰");
			break;
		case 8:
			strcat(result, "拾");
			break;
		case 9:
			strcat(result, "圆");
			break;
		case 10:
			strcat(result, "角");
			break;
		case 11:
			strcat(result, "分");
			break;
		case 12:
			strcat(result, "整");
			break;
	}
	return;
}
void result_function(int array[])
{
	int tmp = 0;
	for (int i = 0; i < 10; ++i) {
		//先处理数字
		if (array[i] != 0) {
			strncat(result, &chnstr[2 * array[i]], 2);
		}
		else {
			if (i != 0 && i != 1&&i!=5) {
				for (int j = 0; j < i; ++j) {
					tmp = tmp + array[j];
				}
				if (tmp > 0 && array[i + 1] > 0&&i!=9) {
					strncat(result, &chnstr[2 * array[i]], 2);
				}
				else if (tmp + array[10] + array[11] == 0 && i == 9) {
					strncat(result, &chnstr[2 * array[i]], 2);
				}
				tmp = 0;
			}
		}
		//处理单位
		if (i != 1 && i != 5 && i != 9) {
			if (array[i] != 0) {
				danwei_function(i);
			}
		}
		else {
			if (i == 1) {
				if (array[0] + array[1]) {
					danwei_function(i);
				}
			}
			else if (i == 5) {
				if (array[2] + array[3] + array[4] + array[5]) {
					danwei_function(i);
				}
			}
			else {
				for (int j = 0; j <= i; ++j) {
					tmp = array[j] + tmp;
				}
				if (tmp==0&&(array[10]!=0||array[11]!=0)) {
					;
				}
				else {
					danwei_function(i);
				}
				
			}
		}
	}
	//角、分单独处理
	if (array[10] == 0 && array[11] == 0) {
		danwei_function(12);
	}
	else if (array[10] != 0 && array[11] == 0) {
		if (array[10] != 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		danwei_function(10);
		danwei_function(12);
	}
	else if (array[10] == 0 && array[11] != 0) {
		for (int j = 0; j < 10; ++j) {
			tmp = tmp + array[j];
		}
		if (tmp > 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		if (array[11]) {
			strncat(result, &chnstr[2 * array[11]], 2);
		}
		danwei_function(11);
	}
	else {
		if (array[10] != 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		if (array[10] != 0) {
			danwei_function(10);
		}
		if (array[11] != 0) {
			strncat(result, &chnstr[2 * array[11]], 2);
		}
		if (array[11] != 0) {
			danwei_function(11);
		}
	}
	return;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	printf("请输入[0-100亿)之间的数字:\n");
	double a, d, x;
	int shuzi[12] = { 0 };
	scanf("%lf", &a);
	a = a + 0.005;                              //弥补实数误差，如果是三位小数就要更小-0.0005，以此类推
	long c;                                     //因为long long在dev中编译不通过，必须用long型
	x = a / 100;								    //将可能溢出的数据变得不溢出（最多11变9位，包不溢出） （此时两位小数变四位小数）
	c = (long)x;									//将浮点数的整数部分存在c中
	d = x - c;								    //将小数部分存在d中

	shuzi[7] = c % 10;									//百位数字

	c = c / 10;
	shuzi[6] = c % 10;									//千位数字

	c = c / 10;
	shuzi[5] = c % 10;									//万位数字

	c = c / 10;
	shuzi[4] = c % 10;									//十万位数字

	c = c / 10;
	shuzi[3] = c % 10;									//百万位数字

	c = c / 10;
	shuzi[2] = c % 10;									//千万位数字

	c = c / 10;
	shuzi[1] = c % 10;									//亿位数字

	c = c / 10;
	shuzi[0] = c % 10;									//十亿位数字

	shuzi[8] = (int)(d * 10);                            //十位数字
	shuzi[9] = (int)((d - shuzi[8] * 0.1) / 0.01);              //圆位数字
	shuzi[10] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9]) / 0.001);									//角位数字
	shuzi[11] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9] - 0.001 * shuzi[10]) / 0.0001);									//分位数字

	printf("大写结果是:\n");
	result_function(shuzi);
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
   
   
    return 0;
}
