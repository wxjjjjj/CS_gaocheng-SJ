/* 计科 2353761 王皙晶 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100)) {
			break;
		}
		else if (ret == 1) {
			printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);           //确认一下，ret的值（即scanf的返回值）是什么含义？ --代表scanf成功读取的有效值个数
		}
		else {
			printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);
			int c;                                                             // 循环读取并丢弃字符，直到遇到换行符  
			while ((c = getchar()) != '\n' && c != EOF) {
				if (c == '\n' && (c = getchar()) != EOF) {
					ungetc(c, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
				}                                                                  // 清除输入缓冲区中的错误字符  
			}
		}
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}