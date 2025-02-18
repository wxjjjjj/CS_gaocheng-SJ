/*王皙晶 2353761 计科*/
/*2352647 上官思洋 2351323 胡昕璟 2350284 张俊峰 2350338 童敬业 2350987 曹欣怡 */
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>

#define maxrow 10
#define maxcolumn 26

void number_of_lei(char array[][maxcolumn])
{
	int number = 0;
	for (int k = 1; k < maxrow - 1; ++k) {

		for (int j = 1; j < maxcolumn - 1; ++j) {

			if (array[k][j] != '*') {
				for (int q = k - 1; q <= k + 1; ++q) {

					for (int p = j - 1; p <= j + 1; ++p) {
						if (array[q][p] == '*') {
							++number;
						}
					}
				}
				array[k][j] = '0' + number;
				number = 0;
			}

		}
	}

	//单独处理边界四个点
	if (array[0][0] != '*') {
		if (array[0][1] == '*') {
			++number;
		}
		if (array[1][1] == '*') {
			++number;
		}
		if (array[1][0] == '*') {
			++number;
		}
		array[0][0] = '0' + number;
		number = 0;
	}
	if (array[0][25] != '*') {
		if (array[0][24] == '*') {
			++number;
		}
		if (array[1][24] == '*') {
			++number;
		}
		if (array[1][25] == '*') {
			++number;
		}
		array[0][25] = '0' + number;
		number = 0;
	}
	if (array[9][25] != '*') {
		if (array[9][24] == '*') {
			++number;
		}
		if (array[8][24] == '*') {
			++number;
		}
		if (array[8][25] == '*') {
			++number;
		}
		array[9][25] = '0' + number;
		number = 0;
	}
	if (array[9][0] != '*') {
		if (array[8][0] == '*') {
			++number;
		}
		if (array[8][1] == '*') {
			++number;
		}
		if (array[9][1] == '*') {
			++number;
		}
		array[9][0] = '0' + number;
		number = 0;
	}

	//处理剩余边界边
	for (int v = 1; v < maxcolumn - 1; ++v) {
		if (array[0][v] != '*') {
			for (int g = 0; g <= 1; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[g][h] == '*') {
						++number;
					}
				}
			}
			array[0][v] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxcolumn - 1; ++v) {
		if (array[9][v] != '*') {
			for (int g = 8; g <= 9; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[g][h] == '*') {
						++number;
					}
				}
			}
			array[9][v] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxrow - 1; ++v) {
		if (array[v][0] != '*') {
			for (int g = 0; g <= 1; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[h][g] == '*') {
						++number;
					}
				}
			}
			array[v][0] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxrow - 1; ++v) {
		if (array[v][25] != '*') {
			for (int g = 24; g <= 25; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[h][g] == '*') {
						++number;
					}
				}
			}
			array[v][25] = '0' + number;
			number = 0;
		}
	}
	return;

}

int main()
{
	char array[maxrow][maxcolumn],array1[maxrow][maxcolumn];
	int number = 0,j=0;
	char c;
	for (int i = 0; i <maxrow ; ++i) {
		while (1) {
			c = getchar();
			if (c == '*' || (c >= '0' && c <= '9')) {
				array[i][j] = c;
				++j;
			}
			if(j==maxcolumn){
				j = 0;
				break;
			}
		}
	}//读入
	

	//判断错误1--数*；
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] == '*') {
				++number;
			}

		}
	}
	if (number != 50) {
		printf("错误1\n");
		return 0;
	}

	//判断错误2
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] == '*') {
				array1[i][j] = array[i][j];
			}

		}
	}
	number_of_lei(array1);
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] !=array1[i][j]) {
				printf("错误2\n");
				return 0;
			}

		}
	}

	//安全下车~
	printf("正确\n");
	return 0;
}
