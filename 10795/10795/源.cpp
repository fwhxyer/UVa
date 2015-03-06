#include <iostream>
#include <cstdio>
using namespace std;

int a[65],b[65];
long long f(int *p,int k,int des){
	if (k==0) return 0;
	if (p[k-1]==des) return f(p,k-1,des);
	else return f(p,k-1,6-des-p[k-1])+(1LL<<(k-1));
}

int main()
{
	int n,T=1;
	while (scanf("%d",&n)!=EOF&&n){
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int i=0;i<n;i++)
			scanf("%d",&b[i]);
		int k=n-1;
		while (a[k]==b[k]&&k>=0) k--;
		long long ans=0;
		if (k>=0) ans=f(a,k,6-b[k]-a[k])+f(b,k,6-b[k]-a[k])+1;
		printf("Case %d: %lld\n",T++,ans);
	}
	return 0;
}
