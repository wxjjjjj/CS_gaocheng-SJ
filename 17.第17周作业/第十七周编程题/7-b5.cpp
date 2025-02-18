/* 2353761 王皙晶 计科 */
#define _CRT_SECURE_NO_WARNINGS
/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <cstring>
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	bool state_1,state_2;  //选课状态0-未选；1-选了/state_1--第一轮选课，state_2--第二轮选课
	//友元声明
	friend class stu_list; 
public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void paixu();//给第一\二轮选课的数组先排序,然后赋给list_merge[MAX_STU_NUM]
	void fenxi();//分析两轮选课数据
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */
void stu_list::paixu()//升序排列，降序输出+处理重复
{
	int k=0;
	student tmp;
	for (int i = 0; i < MAX_STU_NUM-1; ++i) {
		k = i;
		for (int j = i+1; j < MAX_STU_NUM; ++j) {
			if (list_round_1[k].no < list_round_1[j].no) {
				k = j;
			}
		}
		tmp = list_round_1[k];
		list_round_1[k] = list_round_1[i];
		list_round_1[i] = tmp;
	}
	
	//快慢指针处理重复
	student* slow= &list_round_1[1];
	for (int i = 1; list_round_1[i].no != 0; ++i) {
		if (list_round_1[i].no != list_round_1[i - 1].no) {
			*slow = list_round_1[i];
			++slow;
		}
	}
	while ((*slow).no != 0) {
		(*slow).no = 0;
		++slow;
	}
	
	for (int i = 0; i < MAX_STU_NUM - 1; ++i) {
		k = i;
		for (int j = i + 1; j < MAX_STU_NUM; ++j) {
			if (list_round_2[k].no < list_round_2[j].no) {
				k = j;
			}
		}
		tmp = list_round_2[k];
		list_round_2[k] = list_round_2[i];
		list_round_2[i] = tmp;
	}
	slow = &list_round_2[1];
	for (int i = 1; list_round_2[i].no != 0; ++i) {
		if (list_round_2[i].no != list_round_2[i - 1].no) {
			*slow= list_round_2[i];
			++slow;
		}
	}
	while ((*slow).no != 0) {
		(*slow).no = 0;
		++slow;
	}
	return;
}
void stu_list::fenxi()
{
	student* p = &list_round_1[0],*q= &list_round_2[0];
	while (p->no != 0) {
		++p;
	}
	--p;
	while (q->no != 0) {
		++q;
	}
	--q;
	for (int i = 0; i < MAX_STU_NUM; ++i) {
		if ((p->no) == (q->no)) {
			list_merge[i].stu_no = p->no;
			strcpy(list_merge[i].stu_name, p->name);
			--p;
			--q;
		}
		else if ((p->no )> (q->no)) {
			list_merge[i].stu_no = q->no;
			strcpy(list_merge[i].stu_name, q->name);
			--q;
		}
		else {
			list_merge[i].stu_no = p->no;
			strcpy(list_merge[i].stu_name, p->name);
			--p;
		}
		
	}//先整理出名单，再设置状态
	
	for (int i = 0; list_merge[i].stu_no!=0; ++i) {
		list_merge[i].state_1 = 0;
		list_merge[i].state_2 = 0;
		for (int j = 0; j < MAX_STU_NUM; ++j) {
			if (list_round_1[j].no == list_merge[i].stu_no) {
				list_merge[i].state_1 = 1;
			}
		}
		for (int j = 0; j < MAX_STU_NUM; ++j) {
			if (list_round_2[j].no == list_merge[i].stu_no) {
				list_merge[i].state_2 = 1;
			}
		}
		
	}
	return;
}
/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{
	for (int i = 0; i < MAX_STU_NUM; ++i) {
		list_round_1[i].no = 0;
		list_round_2[i].no = 0;
		list_merge[i].stu_no = 0;
	}
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "序号 学号     姓名                             第一轮 第二轮" << endl;
	cout << "============================================================" << endl;
	int i = 0;
	while (list_merge[i].stu_no >0) {
		cout << setw(5) << left << i + 1;
		cout << setw(9) << left << list_merge[i].stu_no;
		cout << setw(33) << left << list_merge[i].stu_name;
		if (list_merge[i].state_1 == 1) {
			cout << "Y      ";
		}
		else {
			cout << "/      ";
		}
		if (list_merge[i].state_2 == 1&& list_merge[i].state_1 == 1) {
			cout << "Y" << endl;
		}
		else if (list_merge[i].state_1 == 0 && list_merge[i].state_2 == 1) {
			cout << "补选" << endl;
		}
		else if (list_merge[i].state_1 == 1 && list_merge[i].state_2 == 0) {
			cout << "退课" << endl;
		}
		i++;
	}
	cout<< "============================================================" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */
	list.paixu();
	list.fenxi();


	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

