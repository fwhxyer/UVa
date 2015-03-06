#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double abss(double a) {return a>0?a:-a;}
int main()
{
	int n,m;
	const double L=10000.0;
	while (scanf("%d%d",&n,&m)!=EOF){
		m+=n;
		double ans=0;
		for (int i=1;i<n;i++){
			ans+=abss(L/n*i-floor(L/n*i/(L/m)+0.5)*(L/m));
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}