#include <iostream>

using namespace std;


int f[6]={0,1,2,3,4,5};

int main()
{
	for (int i=1;i<=6;i++){
		for (int j=1;j<=4;j++)
		{
			printf("{%d,%d,%d,%d,%d,%d},",f[0],f[1],f[2],f[3],f[4],f[5]);
			int t=f[2];
			f[2]=f[1];f[1]=f[3];f[3]=f[4];
			f[4]=t;
		}
		int t;
		switch (i)
		{
		case 1:
			t=f[0];
			f[0]=f[1];f[1]=f[5];f[5]=f[4];
			f[4]=t;
			break;
		case 2:
			t=f[0];
			f[0]=f[2];f[2]=f[5];f[5]=f[3];
			f[3]=t;
			break;
		case 3:
			t=f[0];
			f[0]=f[1];f[1]=f[5];f[5]=f[4];
			f[4]=t;
			t=f[0];
			f[0]=f[1];f[1]=f[5];f[5]=f[4];
			f[4]=t;
			break;
		case 4:
			t=f[0];
			f[0]=f[2];f[2]=f[5];f[5]=f[3];
			f[3]=t;
			break;
		case 5:
			t=f[4];
			f[4]=f[5];f[5]=f[1];f[1]=f[0];
			f[0]=t;
			break;
		default:
			break;
		}
	}
	system("pause");
}