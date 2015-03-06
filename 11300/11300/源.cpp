#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ull;

ull a[1000005];

ull abss(ull a) {return a<0?-a:a;}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF){
		ull mmmm=0;
		for (int i=1;i<=n;i++) {scanf("%lld",&a[i]);mmmm+=a[i];}
		mmmm/=n;
		a[0]=0;
		for (int i=1;i<n;i++)
		{
			a[i]+=(a[i-1]-mmmm);			
			//printf("%I64u\n",a[i]);
		}
		sort(a,a+n);
		ull x=a[n/2],ans=0;
		for (int i=0;i<n;i++) {ans+=abss(a[i]-x);}
		printf("%lld\n",ans);
	}
	return 0;
}