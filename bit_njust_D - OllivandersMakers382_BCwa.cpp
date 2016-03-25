#include<cstdio>
#include<cstring>
using namespace std;
#define m(a,b) a>b?a:b
#define mi(a,b) a<b?a:b
int cal_val(int a,int b,char c)
{
    if(c == 't')
        return a+b;
    else return a*b;
}

int main()
{
    int v,dp[52][52][52],dp_min[52][52][52],val[52],a,b;
    char op[53],tmp_op[53];
    //scanf("%d",&v);
    while(~scanf("%d",&v))
    {getchar();
    for(int i = 0;i <v;++i)
    {
        scanf("%c %d",&op[i],&val[i]);
        getchar();
    }
    for(int i = 0;i < v;++i)
    {
        for(int  j = 1;j<=v;++j)
        {
            dp[i][v][j]=val[(j-1+i)%v];
            tmp_op[j] = op[(j+i)%v];
            dp_min[i][v][j]=val[(j-1+i)%v];
        }

        for(int j = v-1; j; --j)
        {
            for(int k = 1;k <= j;++k)
            {
                a = cal_val(dp[i][j+1][k],dp[i][v][k+v-j],tmp_op[k+v-j-1]);
                b = cal_val(dp[i][v][k],dp[i][j+1][k+1],tmp_op[k]);
                c = cal_val(dp_min[i][j+1][k],dp[i][v][k+v-j],tmp_op[k+v-j-1]);
                d = cal_val(dp_min[i][v][k],dp[i][j+1][k+1],tmp_op[k]);
                dp[i][j][k] = m(a,b);
                dp_min[i][j][k] = mi(c,d);
            }
        }
    }
    int e,m=-0x37373737;
    for(int i = 0;i <v;++i)
    {
        if(m < dp[i][1][1])
        {
            m = dp[i][1][1];
            e = i;
        }
    }
    printf("%d\n",m);
    if(e==v)
    {
        printf("%d %d\n",v,1);
    }else{
        printf("%d %d\n",e,e+1);
    }
    }
    return 0;
}
