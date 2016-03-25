#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
double dp[10050];
int money[10050],sum,n;
double rp[10050];
int main()
{
    int t,i,j;
    double p;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%lf%d",&p,&n);
      memset(dp,0,sizeof(dp));
      sum=0;
      for(i=0;i<n;i++)
      {
        scanf("%d%lf",&money[i],&rp[i]);
        sum+=money[i];
      }
      dp[0]=1;
      for(i=0;i<n;i++)
      {
        for(j=sum;j>=money[i];j--)
        {
           dp[j]=max(dp[j],dp[j-money[i]]*(1-rp[i]));
        }
      }
      for(i=sum;i>=0;i--)
      {
        if(dp[i]>1-p)
        {
           printf("%d\n",i);break;
        }
      }
    }
   // system("pause");
    return 0;
}
