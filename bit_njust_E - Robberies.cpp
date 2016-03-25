#include<cstdio>
#include<cstring>
#define m(a,b) a>b?a:b
using namespace std;
int main()
{
    int t,n,m[105];
    double dp[10005],pm[105],p;
    int sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%d",&p,&n);
        sum = 0;
        for(int i = 0;i < n;++i)
        {
            scanf("%d%lf",&m[i],&pm[i]);
            sum += m[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 0;i < n;++i)
        {
            for(int j = sum;j >= m[i];--j)
            {
                dp[j] = m(dp[j],dp[j-m[i]] * (1-pm[i]));
            }
        }
        for(int i = sum;i>=0;--i)
        {
            if(dp[i] > 1-p)
            {
                printf("%d\n",i);break;
            }
        }
    }
    return 0;
}
