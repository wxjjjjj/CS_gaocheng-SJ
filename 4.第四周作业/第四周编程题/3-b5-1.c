#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	printf("请输入年，月，日\n");
	int a, b, c, d;
	scanf("%d %d %d",&a,&b,&c);          //a是年，b是月，c是日 
	switch (b) {
		case 1:
			if (c >= 0 && c <= 31) {
				d = c;
				printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
			}
			else {
				printf("输入错误-日与月的关系非法\n");
			}
			break;
		case 2:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 29 && c >= 0) {
					d = 31 + c;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 28 && c >= 0) {
					d = 31 + c;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 3:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 4:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 30 && c >= 0) {
					d = 31 + c + 29 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 30 && c >= 0) {
					d = 31 + c + 28 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 5:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 6:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 30 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 30 && c >= 0) {
					d = 31 + 31 + c + 28 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 7:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 8:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 9:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 30 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30 + 31 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 30 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30 + 31 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 10:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 11:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 30 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 30 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		case 12:
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {   //真，则为闰年,二月有29天
				if (c <= 31 && c >= 0) {
					d = 31 + c + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
			else {
				if (c <= 31 && c >= 0) {
					d = 31 + c + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
					printf("%d-%d-%d是%d年的第%d天\n", a, b, c, a, d);
				}
				else {
					printf("输入错误-日与月的关系非法\n");
				}
				break;
			}
		default:
			printf("输入错误-月份不正确\n");
			break;
	}



	return 0;
}
