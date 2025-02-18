#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int i=1,n=1,m;
	while (n <= 9) {
		m = i * n;
		if (i != n) {
			if (m / 10 == 0) {
				printf("%dx%d=%d   ", i, n, m);        //一位乘积空三格
				i = i + 1;
			}
			else {
				printf("%dx%d=%d  ", i, n, m);        //2位乘积空2格
				i= i + 1;
			}
		}
		else {
			if (m / 10 == 0) {
				printf("%dx%d=%d   \n", i, n, m);        //一位乘积空三格
				
			}
			else {
				printf("%dx%d=%d  \n", i, n, m);        //2位乘积空2格
				
			}
			n = n + 1;
			i = 1;
		}
	}
	printf("\n");
	return 0;
}