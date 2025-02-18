/* 2353761 王皙晶 计科 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)//加const代表只读，不可修改*p的指针变量
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p;
    if (str == 0) {//NULL的特判
        return 0;
    }
    else {
        p = str;
        while (*p != 0) {
            ++p;
        }//p指向尾0
        return int(p - str);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL的特殊处理
        return NULL;
    }
    else {
        if (s2 == 0) {
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps1 != 0) {
                ++ps1;
            }//ps1指向s1的尾0
            while (*ps2 != 0) {
                *ps1 = *ps2;
                ++ps2;
                ++ps1;
            }//ps2指向s2尾0
            *ps1 = *ps2;//尾0也复制上
            return s1;
        }
    }
    
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL的特殊处理
        return NULL;
    }
    else {
        if (s2 == 0) {
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps1 != 0) {
                ++ps1;
            }//ps1指向s1的尾0
            if (len >= tj_strlen(s2)) {
                while (*ps2 != 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                }//ps2指向s2尾0
                *ps1 = *ps2;//尾0也复制上
            }
            else {
                int count = len;
                while(count > 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                    --count;
                }
                *ps1 = '\0';
            }
            return s1;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL的特殊处理
        return NULL;
    }
    else {
        if (s2 == 0) {
            *s1 = '\0';
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            while (*ps2 != 0) {
                *ps1 = *ps2;
                ++ps2;
                ++ps1;
            }//ps2指向s2尾0
            *ps1 = *ps2;//尾0也复制上
            return s1;
        }
    }
    
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* ps1;
    const char* ps2;
    if (s1 == 0) {//NULL的特殊处理
        return NULL;
    }
    else {
        if (s2 == 0) {//空串处理
            return s1;
        }
        else {
            ps1 = s1;
            ps2 = s2;
            if (len >= tj_strlen(s2)) {
                while (*ps2 != 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                }//ps2指向s2尾0
            }
            else {
                int count = len;
                while (count > 0) {
                    *ps1 = *ps2;
                    ++ps2;
                    ++ps1;
                    --count;
                }
            }
            return s1;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            while (*ps1!=0&&*ps2!=0) {
                if (*ps1 != *ps2) {
                    return int(*ps1 - *ps2);
                }
                else {
                    ps1++;
                    ps2++;
                }
            }
            if (*ps1 == 0) {
                return -int(*ps2);
            }
            else {
                return int(*ps1);
            }
        }
    }
    
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            while (*ps1 != 0 && *ps2 != 0) {
                if (*ps1 != *ps2) {
                    if (*ps1 >= 'A' && *ps1 <= 'Z') {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            if (*ps2 == *ps1 + 32) {
                                ;
                            }
                            else {
                                return int((*ps1 + 32) - *ps2);
                            }
                        }
                    }
                    else if (*ps1 >= 'a' && *ps1 <= 'z') {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            if (*ps1 == *ps2 + 32) {
                                ;
                            }
                            else {
                                return int(*ps1 - *ps2 - 32);
                            }
                        }
                        else {
                            return int(*ps1 - *ps2);
                        }
                    }
                    else {
                        if (*ps2 >= 'A' && *ps2 <= 'Z') {
                            return int(*ps1 - *ps2 - 32);
                        }
                        else {
                            return int(*ps1 - *ps2);
                        }
                    }
                }
                ps1++;
                ps2++;
            }

            if (*ps1 == 0) {
                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                    return -int(*ps2+32);
                }
                else {
                    return -int(*ps2);
                }
            }
            else {
                if (*ps1 >= 'A' && *ps1 <= 'Z') {
                    return int(*ps1 + 32);
                }
                else {
                    return int(*ps1);
                }
            }
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            int i = tj_strlen(s1) - tj_strlen(s2);
            if (i > 0) {//s2短
                if (len > tj_strlen(s2)) {
                    while (*ps2 != 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                    }//ps2指在s2尾0
                    return int(*ps1);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                        --a;
                    }
                    return 0;
                }
            }
            else {
                if (len > tj_strlen(s1)) {
                    while (*ps1 != 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                    }//ps1指在s1尾0
                    return -int(*ps2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            return int(*ps1 - *ps2);
                        }
                        else {
                            ps1++;
                            ps2++;
                        }
                        --a;
                    }
                    return 0;
                }
            }
            
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* ps1, * ps2;
    ps1 = s1;
    ps2 = s2;
    if (s1 == 0) {
        if (s2 == 0) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        if (s2 == 0) {
            return 1;
        }
        else {
            int i = tj_strlen(s1) - tj_strlen(s2);
            if (i > 0) {//s2短
                if (len > tj_strlen(s2)) {
                    return tj_strcasecmp(s1, s2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            if (*ps1 >= 'A' && *ps1 <= 'Z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2);
                                }
                                else {
                                    if (*ps2 == *ps1 + 32) {
                                        ;
                                    }
                                    else {
                                        return int((*ps1 + 32) - *ps2);
                                    }
                                }
                            }
                            else if (*ps1 >= 'a' && *ps1 <= 'z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    if (*ps1 == *ps2 + 32) {
                                        ;
                                    }
                                    else {
                                        return int(*ps1 - *ps2 - 32);
                                    }
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                            else {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2 - 32);
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                        }
                        ps1++;
                        ps2++;
                        --a;
                    }
                    return 0;
                }
            }
            else {
                if (len > tj_strlen(s1)) {
                    return tj_strcasecmp(s1, s2);
                }
                else {
                    int a = len;
                    while (a > 0) {
                        if (*ps1 != *ps2) {
                            if (*ps1 >= 'A' && *ps1 <= 'Z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2);
                                }
                                else {
                                    if (*ps2 == *ps1 + 32) {
                                        ;
                                    }
                                    else {
                                        return int((*ps1 + 32) - *ps2);
                                    }
                                }
                            }
                            else if (*ps1 >= 'a' && *ps1 <= 'z') {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    if (*ps1 == *ps2 + 32) {
                                        ;
                                    }
                                    else {
                                        return int(*ps1 - *ps2 - 32);
                                    }
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                            else {
                                if (*ps2 >= 'A' && *ps2 <= 'Z') {
                                    return int(*ps1 - *ps2 - 32);
                                }
                                else {
                                    return int(*ps1 - *ps2);
                                }
                            }
                        }
                        ps1++;
                        ps2++;
                        --a;
                    }
                    return 0;
                }
            }

        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p=str;
        while (*p!= 0) {
            if (*p >= 'a' && *p <= 'z') {
                *p = *p - 32;
            }
            ++p;
        }
        return str;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p = str;
        while (*p != 0) {
            if (*p >= 'A' && *p <= 'Z') {
                *p = *p + 32;
            }
            ++p;
        }
        return str;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p=str;
    int n = 1;
    if (str == 0) {
        return 0;
    }
    else {
        while (*p != 0) {
            if (*p == ch) {
                return n;
                break;
            }
            ++n;
            ++p;
        }
        return 0;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == 0 || substr == 0) {
        return NULL;
    }
    else {
        const char* p = str;
        int n = 1;
        while (*p != 0) {
            if (*p == *substr) {
                const char* m = substr;
                int j = tj_strncmp(p, substr,tj_strlen(substr));
                if (j == 0) {
                    return n;
                }
                else {
                    ;
                }
            }
            ++p;
            ++n;
        }
        return 0;

    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p = str;
    int n = 1;
    if (str == 0) {
        return 0;
    }
    else {
        while (*p != 0) {
            ++p;
            ++n;
        }//p指向str尾0
        while (p != str) {
            --p;
            --n;
            if (*p == ch) {
                return n;
                break;
            }
        }
        if (*str == ch) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == 0 || substr == 0) {
        return NULL;
    }
    else {
        const char* p = str;
        int n = 1;
        while (*p != 0) {
            ++p;
            ++n;
        }
        while (p != str) {
            --p;
            --n;
            if (*p == *substr) {
                const char* m = substr;
                int j = tj_strncmp(p, substr, tj_strlen(substr));
                if (j == 0) {
                    return n;
                }
                else {
                    ;
                }
            }
        }
        return 0;

    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == 0) {
        return NULL;
    }
    else {
        char* p, * q;
        p = str;
        q = str;
        while (*p != 0) {
            ++p;
        }//p指向str的尾0
        --p;
        while (p !=q) {
            if (p - q < 0) {
                break;
            }
            char tmp;
            tmp = *p;
            *p = *q;
            *q = tmp;
            --p;
            ++q;
        }
        return str;
    }
}
