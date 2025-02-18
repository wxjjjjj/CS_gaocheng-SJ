#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c,ret;//a是年，b是月,c是星期

	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &a, &b);
		if (ret == 0||ret==1) {
			int cc;                                                             // 循环读取并丢弃字符，直到遇到换行符  
			while ((cc = getchar()) != '\n' && cc != EOF) {
				if (cc == '\n' && (cc = getchar()) != EOF) {
					ungetc(cc, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
				}                                                                  // 清除输入缓冲区中的错误字符  
			}
			printf("输入非法，请重新输入\n");
		}
		else {
			if ((a >= 2000 && a <= 2030 && b >= 1 && b <= 12) == 0) {
				printf("输入非法，请重新输入\n");
			}
			else {
				while (1) {
					printf("请输入%d年%d月1日的星期（0-6表示星期日-星期六) : ",a,b);
					int ret2;
					ret2 = scanf("%d", &c); 
					if (ret2 == 0) {
						int ccc;                                                             // 循环读取并丢弃字符，直到遇到换行符  
						while ((ccc = getchar()) != '\n' && ccc != EOF) {
							if (ccc == '\n' && (ccc = getchar()) != EOF) {
								ungetc(ccc, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
							}                                                                  // 清除输入缓冲区中的错误字符  
						}
						printf("输入非法，请重新输入\n");
					}
					else {
						if ((c >= 0 && c <= 6) == 0) {
							printf("输入非法，请重新输入\n");
						}
						else {
							break;
						}
					}
				}
				break;
			}
		}
	}

	printf("\n");
	printf("%d年%d月的月历为:\n",a,b);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六  \n");
	int d = 1;
	switch (c) {
		case 0:
			printf("%4d",d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 0) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 1:
			printf("%12d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 6) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 2:
			printf("%20d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 5) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 3:
			printf("%28d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 4) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 4:
			printf("%36d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 3) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 5:
			printf("%44d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 2) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 6:
			printf("%52d\n", d);
			for (d = 2; d <= 31; d++) {
				if (d == 2) {
					printf("%4d", d);
					d++;
				}
				printf("%8d", d);
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//闰年
					if (b == 2 && d == 29) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//不是闰年
					if (b == 2 && d == 28) {//2月
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				if (d % 7 == 1) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;

	}
	printf("\n");
	return 0;
}
