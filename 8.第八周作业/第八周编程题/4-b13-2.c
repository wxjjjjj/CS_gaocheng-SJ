/* 2353761 王皙晶 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

int count = 0;
/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		++count;
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++count;
	printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int layers,ret,ret1,ret2;
	char src, dst, tmp;//layers是层，src是起始柱,dst是目标柱,tmp是辅助柱

	while (1) {
		printf("请输入汉诺塔的层数(1-16)\n");
		ret=scanf("%d", &layers);
		if (ret == 0) {
			int c;                                                             // 循环读取并丢弃字符，直到遇到换行符  
			while ((c = getchar()) != '\n' && c != EOF) {
				if (c == '\n' && (c = getchar()) != EOF) {
					ungetc(c, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
				}                                                                  // 清除输入缓冲区中的错误字符  
			}
		}
		else {
			int d;                                                             // 循环读取并丢弃字符，直到遇到换行符  
			while ((d = getchar()) != '\n' && d != EOF) {
				if (d == '\n' && (d = getchar()) != EOF) {
					ungetc(d, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
				}                                                                  // 清除输入缓冲区中的错误字符  
			}
			if (layers >= 1 && layers <= 16) {
				while (1) {
					printf("请输入起始柱(A-C)\n");
					ret1=scanf("%c",&src);
					if (ret1 == 0) {
						int e;                                                             // 循环读取并丢弃字符，直到遇到换行符  
						while ((e = getchar()) != '\n' && e != EOF) {
							if (e == '\n' && (e = getchar()) != EOF) {
								ungetc(e, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
							}                                                                  // 清除输入缓冲区中的错误字符  
						}
					}
					else {
						int f;                                                             // 循环读取并丢弃字符，直到遇到换行符  
						while ((f = getchar()) != '\n' && f != EOF) {
							if (f == '\n' && (f = getchar()) != EOF) {
								ungetc(f, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
							}                                                                  // 清除输入缓冲区中的错误字符  
						}
						if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
							while (1) {
								printf("请输入目标柱(A-C)\n");
								ret2=scanf("%c",&dst);
								if (ret2 == 0) {
									int g;                                                             // 循环读取并丢弃字符，直到遇到换行符  
									while ((g = getchar()) != '\n' && g != EOF) {
										if (g == '\n' && (g = getchar()) != EOF) {
											ungetc(g, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
										}                                                                  // 清除输入缓冲区中的错误字符  
									}
								}
								else {
									int h;                                                             // 循环读取并丢弃字符，直到遇到换行符  
									while ((h = getchar()) != '\n' && h != EOF) {
										if (h == '\n' && (h = getchar()) != EOF) {
											ungetc(h, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
										}                                                                  // 清除输入缓冲区中的错误字符  
									}
									if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
										if (src == dst || src == dst + 32 || src == dst - 32) {
											if (src >= 'a' && src <= 'c') {
		                                        src = src - 32;
	                                        }
	                                        if (dst >= 'a' && dst <= 'c') {
		                                        dst = dst - 32;
	                                        }
											printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
										}
										else {
											break;
										}
									}

								}
							}
							break;
						}
					}
				}
				break;
			}
		}
	}                //输入部分处理完毕

	printf("移动步骤为:\n");
	if (src >= 'a' && src <= 'c') {
		src = src - 32;
	}
	if (dst >= 'a' && dst <= 'c') {
		dst = dst - 32;
	}
	if ((src == 'A' || src == 'B') && (dst == 'A' || dst == 'B')) {
		tmp = 'C';
	}
	else if ((src == 'A' || src == 'C') && (dst == 'A' || dst == 'C')) {
		tmp = 'B';
	}
	else {
		tmp = 'A';
	}
	hanoi(layers, src, tmp, dst);

	return 0;
}
