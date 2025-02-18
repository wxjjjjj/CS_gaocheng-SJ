/* 计科 2353761 王皙晶*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a,b,c,i,j,l,g,h,k;          //a是百位数字，b是十位数字，c是个位数字
	int d,e,f,sum,count=0;                //d,e,f是和1953的数 
	for(d=111;d<=999;d++){
		for(e=111;e<=999;e++){
			for(f=111;f<=999;f++){
				sum=d+e+f;
				if(sum==1953){
					a=d/100;   //d的百位数字
					b=d%100/10;   //d的十位数字
					c=d%100%10;		//d的个位数字
					i=e/100;   //e的百位数字
					j=e%100/10;   //e的十位数字
					l=e%100%10;		//e的个位数字
					g=f/100;   //f的百位数字
					h=f%100/10;   //f的十位数字
					k=f%100%10;		//f的个位数字
					if(a!=0&&b!=0&&c!=0&&i!=0&&j!=0&&l!=0&&g!=0&&h!=0&&k!=0&&j!=g&&j!=h&&j!=k&&l!=g){
						if(d<e&&e<f&&d<f){
							if(a!=b&&b!=c&&a!=c&&a!=i&&a!=j&&a!=l&&a!=g&&a!=h&&a!=k&&l!=k){
								if(i!=l&&j!=i&&l!=j&&b!=i&&b!=j&&b!=l&&b!=g&b!=h&&b!=k){
									if(g!=h&&k!=g&&h!=k&&c!=i&&c!=j&&c!=l&&c!=g&&c!=h&&c!=k&&i!=g&&i!=h&&i!=k){
										count=count+1;
							    	    printf("No.%3d : %d+%d+%d=1953\n",count,d,e,f);
							        }
							        else{
							        	break;
						    	    }
						        }
							
						    }
						
					    }
					}
					
				}	
			}	
		}
	}


	printf("total:%d\n",count);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
