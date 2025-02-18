/*2353761 王皙晶 计科*/
#include<iostream>

using namespace std;    //ps:不要用cin读取，因为cin会天然跳过空格和回车的读取
                        //_getche--有回显 的回车是\r；而getchar--有回显 是\n

int main()
{
    char str[3][128] = { 0};//str0代表第一行输入的文字
    int daxie = 0, xiaoxie = 0, number = 0, space=0,others = 0;
    for (int i = 0; i < 3; ++i) {
        cout << "请输入第" << i+1 << "行" << endl;
        cin.getline(str[i], 128);
    }//完成输入
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 128; ++j) {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z') {//大写计数
                daxie++;
            }
            else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
                xiaoxie++;
            }
            else if (str[i][j] >= '0' && str[i][j] <= '9') {
                number++;
            }
            else if (str[i][j] == ' ') {
                space++;
            }
            else {
                if (str[i][j] != 0) {
                    others++;
                }
            }
        }
    }

    cout << "大写 : " << daxie<<endl;
    cout << "小写 : " << xiaoxie << endl;
    cout << "数字 : " << number << endl;
    cout << "空格 : " << space << endl;
    cout << "其它 : " << others << endl;

    return 0;
}
