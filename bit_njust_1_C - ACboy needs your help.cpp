#include<cstdio>
#include<cstring>
#define m(a,b) a>b?a:b
using namespace std;
int main()
{
    int N,M;
    int a[105][105];
    int dp[105];

    while(scanf("%d%d",&N,&M),M+N)
    {
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < N;++i)
        {
            for(int j = 1;j <= M;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }

        for(int i = 0;i<N;++i)
        {
            for(int j = M;j>0;--j)
            {
                for(int k = j;k > 0;--k)
                    dp[j] = m(dp[j],dp[j-k]+a[i][k]);
            }
        }

        printf("%d\n",dp[M]);
    }
    return 0;
}
