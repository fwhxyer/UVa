#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

pair<int ,int > a[1001];

bool cmp(pair<int ,int > a,pair<int ,int > b){
	if (a.second>b.second)
		return true;
	else if (a.second<b.second)
		return false;
	if (a.first>b.first)
		return true;
	return false;
}

int main()
{
	int n,T=1;
	pair<int ,int > itmp;
	while (scanf("%d",&n)!=EOF && n!=0){
		for (int i=0;i<n;i++) {scanf("%d%d",&itmp.first,&itmp.second);a[i]=itmp;}
		sort(a,a+n,cmp);
		int ans1=0,ans2=0;
		for (int i=0;i<n;i++){
			ans1+=a[i].first;
			if (ans2<ans1+a[i].second) ans2=ans1+a[i].second;
		}
		printf("Case %d: %d\n",T++,ans2);
	}
	return 0;
}