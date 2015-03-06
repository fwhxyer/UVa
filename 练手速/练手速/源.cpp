#include <iostream>
#include <stdio.h>
using namespace std;

int a[10000];

int main ()
{
	int T;
	scanf_s("%d",&T);
	int n;
	while (scanf_s("%d",&n)!=EOF&&n!=0)
	{		
		for (int i=0;i<n;i++)
			scanf_s("%d",&a[i]);
		for (int i=0;i<n;i++)	{
			for (int j=0;j<a[i];j++)
				printf("*");
			printf("\n");
		}
	}
	return 0;
}