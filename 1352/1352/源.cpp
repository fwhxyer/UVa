#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> colorName;
int getColorID(char *s){
	string str(s);
	for (int i=0;i<colorName.size();i++)
		if (str==colorName[i]) return i;
	colorName.push_back(str);
	return colorName.size()-1;
}

int countColor[30];
int color[4][6];
int colorU[4][6];
int n,ans;
//changeColor
int cC[24][6]={
{0,1,2,3,4,5},{0,3,1,4,2,5},{0,4,3,2,1,5},{0,2,4,1,3,5},{1,5,2,3,0,4},{1,3,5,0,2
,4},{1,0,3,2,5,4},{1,2,0,5,3,4},{2,5,4,1,0,3},{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0
,5,1,3},{3,0,4,1,5,2},{3,1,0,5,4,2},{3,5,1,4,0,2},{3,4,5,0,1,2},{4,0,2,3,5,1},{4
,3,0,5,2,1},{4,5,3,2,0,1},{4,2,5,0,3,1},{5,4,2,3,1,0},{5,3,4,1,2,0},{5,1,3,2,4,0
},{5,2,1,4,3,0}
};

void dfs(int tt){
	if (tt<0){
		int anst=0;
		for (int j=0;j<6;j++){
			memset(countColor,0,sizeof(countColor));
			int maxA=0;
			for (int i=0;i<n;i++)
			{
				countColor[colorU[i][j]]++;
				if (countColor[colorU[i][j]]>maxA) maxA=countColor[colorU[i][j]];
			}
			anst+=n-maxA;
		}
		if (anst<ans) ans=anst;
	}else{
		for (int i=0;i<24;i++)
		{
			for (int j=0;j<6;j++)
				colorU[tt][j]=color[tt][cC[i][j]];
			dfs(tt-1);
		}
	}
}

int main()
{
	char s[30];
	while (scanf("%d",&n)!=EOF&&n){
		for (int i=0;i<n;i++)
			for (int j=0;j<6;j++){
				scanf("%s",s);
				color[i][j]=getColorID(s);
			}
		ans=100;
		dfs(n-1);
		printf("%d\n",ans);
	}
	return 0;
}