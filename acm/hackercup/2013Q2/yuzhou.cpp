#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 1010
#define P 1000000007
int t,n,s[N],f[N][N],he[N],ne[N*2],ad[N*2],C[N][N];bool di[N*2];
void addE(int x,int y,bool z)
{
	++t,ne[t]=he[x],he[x]=t,ad[t]=y,di[t]=z;
	++t,ne[t]=he[y],he[y]=t,ad[t]=x,di[t]=!z;
}
int g[N],f2[N];
void ff(int x,int y)
{
	f[x][0]=1,s[x]=1;
	for(int p=he[x];p;p=ne[p])
		if(ad[p]!=y)
		{
			ff(ad[p],x);
			memset(g,0,sizeof g);
			for(int i=1;i<=s[ad[p]];i++)
				g[i]=(g[i-1]+f[ad[p]][i-1])%P;
			// s[x] += s[ad[p]]
			memset(f2,0,sizeof f2);
			bool z=di[p];
			for(int i=0;i<=s[ad[p]];i++)
			{
				if(z&&i==0)continue;
				if((!z)&&i==s[ad[p]])continue;
				ll c;
				if(z)c=g[i];else c=(g[s[ad[p]]]-g[i]+P)%P;
				for(int j=0;j<s[x];j++)
					f2[i+j]=(f2[i+j]+(ll)f[x][j]*c%P*C[i+j][i]%P*C[s[x]+s[ad[p]]-(i+j)-1][s[ad[p]]-i]%P)%P;
			}
			s[x]+=s[ad[p]];
			for(int j=0;j<s[x];j++)f[x][j]=f2[j];
		}
}
int main()
{
    freopen("permutations_1.txt", "r", stdin);
    freopen("permutations_yuzhou.out", "w", stdout);
	C[0][0]=1;
	for(int i=1;i<N;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d",&n);
		memset(he,0,sizeof he),t=0;
		for(int i=1;i<n;i++)
		{
			char s[5];int x,y;
			scanf("%d%s%d",&x,s,&y);
			addE(x,y,(s[0]=='>'));
		}
		memset(f,0,sizeof f),
		memset(s,0,sizeof s);
		ff(0,-1);
		/*
		for(int i=0;i<n;i++)
		{
			printf("%d",s[i]);
			for(int j=0;j<s[i];j++)
				printf(" %d",f[i][j]);
			puts("");
		}
		*/
		int S=0;
		for(int i=0;i<n;i++)(S+=f[0][i])%=P;
		printf("Case #%d: %d\n",__,S);
	}
	return 0;
}
