/* 计科 2353761 王皙晶*/
#pragma once
/*放一些const和函数声明
放上述源程序文件的公用声明部分及其它所需内容*/

void Input(int* hang, int* lie);
void print(void);
void print_array(int hang, int lie, int array[][9], int visited[][9], int gongnenghao);
void array_A(int hang, int lie, int array[][9], int number_ball);
void chushihua_array(int array[][9], int hang, int lie);
void input_move_instruction(int src, int dst, int array[][9], int hang, int lie, int gongnenghao, int* sum_score);
void judge_input(char str[], int hang, int lie, int x, int y);
void search_for_path(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int hang, int lie, int visited[][9], int* result, int gongnenghao, int x, int y);
void generation_of_3_ball(int ball[]);
void change_array_and_print(int src_x, int src_y, int dst_x, int dst_y, int array[][9], int hang, int lie, int ball[], int* sum_score);
int get_score(int array[][9], int* sum_score, int hang, int lie, int ball[],int gongnenghao);
bool judge_full(int array[][9], int hang, int lie);
void draw_border_pause();
void draw_border(int array[][9], int hang, int lie);
void draw_border_pro(int array[][9], int hang, int lie);
void move_by_mouse(int hang, int lie, int array[][9], int gongnenghao);
void movement_ball(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int result, int gongnenghao, int x, int y);
void update_array(int array[][9], int& flag_y, int& flag_x, int& flag_first, int& flag_second, int& array_src_x, int& array_src_y, int& array_dst_x, int& array_dst_y,int hang,int lie,int ball[],int* sum_score);
void draw_real_time(int ball[],int array[][9],int hang,int lie);
void draw_score();
void draw_sort(int array[][9],int hang,int lie);
int cal_number(int array[][9], int hang, int lie, int color);