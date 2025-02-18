#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d) //已经定义了y，m，d函数内不用再定义
{
	int c, w, q;
	q = y;    //年份存在q内不动
	c = y / 100;
	y = y - c * 100;
	if (m == 1) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 13;
	}
	else if (m == 2) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 14;
	}
	else {
		m = m;
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w = w + 7;
	}
	w = w % 7;
	return w;
}

int main()
{
	int a, b, c, ret,l;//a是年，b是月,c是星期

	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret=scanf("%d %d %d", &a, &b, &c);
		if (ret == 0 || ret == 1||ret==2) {
			int cc;                                                             // 循环读取并丢弃字符，直到遇到换行符  
			while ((cc = getchar()) != '\n' && cc != EOF) {
				if (cc == '\n' && (cc = getchar()) != EOF) {
					ungetc(cc, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
				}                                                                  // 清除输入缓冲区中的错误字符  
			}
			printf("输入错误，请重新输入\n");
		}
		else {
			if (a < 1900 || a>2100) {
				printf("年份不正确，请重新输入\n");
			}
			else {
				if (b > 12 || b < 1) {
					printf("月份不正确，请重新输入\n");
				}
				else {  //看日的正确性
					if (b == 2) {
						if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {  //闰年二月
							if (c >= 0 && c <= 29) {
								break;
							}
							else {
								printf("日不正确，请重新输入\n");
							}
						}
						else {
							if (c >= 0 && c <= 28) {
								break;
							}
							else {
								printf("日不正确，请重新输入\n");
							}
						}
					}
					else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
						if (c >= 0 && c <= 31) {
							break;
						}
						else {
							printf("日不正确，请重新输入\n");
						}

					}
					else {
						if (c >= 0 && c <= 30) {
							break;
						}
						else {
							printf("日不正确，请重新输入\n");
						}
					}
				}
			}
		}
	}
	l = zeller(a, b, c);
	switch (l) {
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
		case 0:
			printf("星期日\n");
			break;
		default:
			break;
	}
	return 0;
}
