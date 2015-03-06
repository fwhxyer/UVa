#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int a[17][17],b[17][17];
int T,TT=1,ans=100000,n;

void dfs(int p){
	if (p<=n){
		b[1][p]=1;
		dfs(p+1);
		b[1][p]=0;
		dfs(p+1);
	}else
	{
		for (int i=2;i<=n+1;i++)
			for (int j=0;j<=n+1;j++)
				b[i][j]=0;
		for (int i=1;i<n;i++)
			for (int j=1;j<=n;j++)
			{
				if ((b[i-1][j]+b[i][j+1]+b[i][j-1])%2) b[i+1][j]=1;
				else b[i+1][j]=0;
			}
		bool flag=true;int anst=0;
		for (int i=1;i<=n;i++)
			if ((b[n-1][i]+b[n][i-1]+b[n][i+1])%2) {flag=false;break;}
		if (flag)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				if (a[i][j]&&!b[i][j]) {flag=false;break;}
				else if (!a[i][j]&&b[i][j]) {anst++;}
			}
		if (flag)
			if (anst<ans) ans=anst;
	}
}

int main()
{
	scanf("%d",&T);
	while (T--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		ans=100000;
		dfs(1);
		if (ans==100000)
			printf("Case %d: %d\n",TT++,-1);
		else
			printf("Case %d: %d\n",TT++,ans);
	}
	return 0;
}