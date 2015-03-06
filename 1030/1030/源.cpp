#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)

char a[6][10][10];
char b[10][10][10];

int n;

int visible(int d,int x,int y,int z) {
	if (d==0) {for (int i=y-1;i>=0;i--) if (b[x][i][z]=='y') return 0;return (int)a[0][x][z];}
	if (d==1) {for (int i=x-1;i>=0;i--) if (b[i][y][z]=='y') return 0;return (int)a[1][n-1-y][z];}
	if (d==2) {for (int i=y+1;i<n;i++) if (b[x][i][z]=='y') return 0;return (int)a[2][n-1-x][z];}
	if (d==3) {for (int i=x+1;i<n;i++) if (b[i][y][z]=='y') return 0;return (int)a[3][y][z];}
	if (d==4) {for (int i=z-1;i>=0;i--) if (b[x][y][i]=='y') return 0;return (int)a[4][x][n-1-y];}
	if (d==5) {for (int i=z+1;i<n;i++) if (b[x][y][i]=='y') return 0;return (int)a[5][x][y];}
}

int main()
{
	char c;
	while (scanf("%d",&n)!=EOF && n!=0){
		scanf("%c",&c);
		memset(a,0,sizeof(a));
		REP(i,n) {
			REP(k,6){
				REP(j,n)
					scanf("%c",&a[k][j][i]);
				scanf("%c",&c);
			}
		}

		memset(b,'y',sizeof(b));
		REP(j,n) {
		REP(k,n) {
			if (a[0][j][k]=='.')
				REP(i,n){
					b[j][i][k]='n';
				}
			if (a[1][j][k]=='.')
				REP(i,n){
					b[i][n-1-j][k]='n';
				}
			if (a[2][j][k]=='.')
				REP(i,n){
					b[n-1-j][i][k]='n';
				}
			if (a[3][j][k]=='.')
				REP(i,n){
					b[i][j][k]='n';
				}
			if (a[4][j][k]=='.')
				REP(i,n){
					b[j][n-1-k][i]='n';
				}
			if (a[5][j][k]=='.')
				REP(i,n){
					b[j][k][i]='n';
				}
		}}

		bool flag=true;
		while (flag){
			flag=false;
			REP(i,n) {
			REP(j,n) {
			REP(k,n) 
			if (b[i][j][k]=='y'){
				int v[6],num=0;
				REP(vv,6){
					v[vv]=visible(vv,i,j,k);
					if (v[vv]) {v[num]=v[vv];num++;}
				}
				REP (vv,num-1){
					if (v[vv]!=v[vv+1]){b[i][j][k]='n';flag=true;break;}
				}
			}}}
		}

		int ans=0;
		REP(i,n) {
		REP(j,n) {
		REP(k,n) {
			if (b[i][j][k]=='y') ans++;
		}}}
		printf("Maximum weight: %d gram(s)\n",ans);
	}
	return 0;
}