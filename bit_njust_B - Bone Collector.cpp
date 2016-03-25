#include<cstdio>
#include<cstring>
using namespace std;
#define ML(a,b) a>b?a:b
int main()
{
    int t,num,V;
    int Val[1005],dp[1005],weight[1005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&num,&V);
        for(int i = 0;i < num;++i)
        {
            scanf("%d",Val+i);
        }
        for(int i = 0;i <num;++i)
        {
            scanf("%d",weight+i);
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<num;++i)
        {
            for(int j = V;j>=weight[i];--j)
            {
               dp[j] = ML(dp[j],(Val[i]+dp[j-weight[i]]));
            }
        }
        printf("%d\n",dp[V]);

    }
    return 0;
}
