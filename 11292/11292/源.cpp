#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int a[20001],b[20001];
int main()
{
	int m,n;
	while (scanf("%d%d",&n,&m)!=EOF&&!(m==0&&n==0)){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<m;i++)
			scanf("%d",&b[i]);
		if (n>m) {printf("Loowater is doomed!\n");continue;}
		sort(a,a+n);
		sort(b,b+m);
		int j=0,ans=0;
		bool find=true;
		for (int i=0;i<n;i++){
			while (j<m&&b[j]<a[i]) j++;
			if (j>=m) {find=false;break;}
			ans+=b[j];
			j++;
		}
		if (find) printf("%d\n",ans);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
