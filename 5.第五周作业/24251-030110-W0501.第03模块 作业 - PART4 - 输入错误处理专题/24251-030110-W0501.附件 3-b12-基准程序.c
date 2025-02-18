/* 计科 2353761 王皙晶 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ret, x;
    int valid_input = 0; // 标记是否有有效输入  

    while (!valid_input) {
        printf("请输入x的值[0-100] : ");
        ret = scanf("%d", &x);//读入x的方式必须是scanf且格式符为%d，不准用非scanf

        if (ret == 1) {                                                      
            if (x >= 0 && x <= 100) {
                valid_input = 1; // 有效输入，退出循环  
            }
            else {
                // x不在有效范围内，但scanf成功读取了一个整数（尽管它不在范围内）  
                printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);           //确认一下，ret的值（即scanf的返回值）是什么含义？ --代表scanf成功读取的有效值个数
                // 不需要清除输入缓冲区，因为scanf已经读取了整个整数  
            }
        }
        else {    // scanf未能读取整数，可能是输入了字母或其他非数字字符  
            while (1) {
                printf("输入有错[ret=%d x=%d],请重新输入\n", ret, x);
                int c;                                                             // 循环读取并丢弃字符，直到遇到换行符  
                while ((c = getchar()) != '\n' && c != EOF) {
                    if (c == '\n' && (c = getchar()) != EOF) {
                        ungetc(c, stdin);                                              // 将读取的额外字符放回输入流（如果不是EOF）  
                    }                                                                  // 清除输入缓冲区中的错误字符  
                }
                printf("请输入x的值[0-100] : ");                                                                  // 如果换行符后还有字符（例如，在Windows中可能有一个额外的'\r'），也丢弃它  
                ret = scanf("%d", &x);//读入x的方式必须是scanf且格式符为%d，不准用非scanf
                if (ret == 1) {
                    break;
                }

            }
            
        }

        // 在重新提示用户输入之前，确保输入缓冲区是空的  
    }

    printf("有效输入: x = %d\n", x);

    return 0;
}


