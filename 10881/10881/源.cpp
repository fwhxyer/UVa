#include<iostream>
#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;

struct A{
	int o;
	bool d;
	int b;//begin
	long long f;//final
};
A a[10005];
int b[10005];
bool cmp(A a,A b){if (a.f<b.f) return true;return false;}
bool cmp1(A a,A b){if (a.b<b.b) return true;return false;}

int main()
{
	int T,l,t,n,TT=1;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d%d",&l,&t,&n);
		char dir,dir1;
		int tmp,p=0,q=0;
		for (int i=0;i<n;i++){
			scanf("%d%c%c",&tmp,&dir1,&dir);
			a[i].o=i;
			a[i].b=tmp;
			if (dir=='R'&&tmp+t>l) { 
				q++;
				a[i].f=2147483647;
				a[i].d=1;
			}else if (dir=='L'&&tmp-t<1) { 
				p++;
				a[i].f=-1;
				a[i].d=0;
			}else {
				if (dir=='R'){
					a[i].f=tmp+t;
					a[i].d=1;
				}else{
					a[i].f=tmp-t;
					a[i].d=0;
				}
			}
		}
		sort(a,a+n,cmp1);
		for (int i=0;i<n;i++){
			b[a[i].o]=i;
		}
		sort(a,a+n,cmp);
		printf("Case #%d:\n",TT++);
		for (int i=0;i<n;i++){
			int p=b[i];
			if (a[p].f<0||a[p].f==2147483647) 
				printf("Fell off\n");
			else {
				printf("%d ",a[p].f);
				if ((p>0&&a[p-1].f==a[p].f)||(p<n-1&&a[p+1].f==a[p].f))
					printf("Turning\n");
				else { 
					if (a[p].d)
						printf("R\n");
					else
						printf("L\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}