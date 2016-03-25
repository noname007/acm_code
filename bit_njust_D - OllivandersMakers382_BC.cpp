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
    int v,dp[52][52][52],dp_min[52][52][52],val[52],a,b,c,d,e,f,g,h;
    char op[53],tmp_op[53];
    //scanf("%d",&v);
    while(~scanf("%d",&v)){
        getchar();
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


                a = cal_val(dp[i][j+1][k],dp[i][v][v-j+k],tmp_op[v-j+k-1]);

                b = cal_val(dp[i][j+1][k+1],dp[i][v][k],tmp_op[k]);

                c = cal_val(dp_min[i][v][k],dp_min[i][j+1][k+1],tmp_op[k]);

                d = cal_val(dp_min[i][j+1][k],dp_min[i][v][v-j+k],tmp_op[v-j+k-1]);

                e = cal_val(dp_min[i][j+1][k],dp[i][v][v-j+k],tmp_op[v-j+k-1]);

                f = cal_val(dp_min[i][j+1][k+1],dp[i][v][k],tmp_op[k]);

                g = cal_val(dp[i][j+1][k],dp_min[i][v][v-j+k],tmp_op[v-j+k-1]);

                h = cal_val(dp[i][j+1][k+1],dp_min[i][v][k],tmp_op[k]);


                if(tmp_op[v-j+k-1] == 'x')
                {
                    dp[i][j][k] = m(a,d);
                    dp_min[i][j][k] = mi(e,g);
                    dp_min[i][j][k] = mi(dp_min[i][j][k],d);

                }else{
                    dp[i][j][k] = a;
                    dp_min[i][j][k] = d;
                }

                if(tmp_op[k] == 'x')
                {
                    dp[i][j][k] = m(b,dp[i][j][k]);
                    dp[i][j][k] = m(c,dp[i][j][k]);

                    dp_min[i][j][k] = mi(f,h) < dp_min[i][j][k]?mi(f,h):dp_min[i][j][k];
                    dp_min[i][j][k] = mi(dp_min[i][j][k],c);
                }else{
                    dp[i][j][k] = m(b,dp[i][j][k]);
                    dp_min[i][j][k] = mi(dp_min[i][j][k],c);
                }
            }
        }
    }
    int m=-0x37373737,s[54],top = 0;
    for(int i = 0;i <v;++i)
    {
        if(m < dp[i][1][1])
        {
            m = dp[i][1][1];
            top = 1;
            s[0] = i;
        }else if(m==dp[i][1][1]){
            s[top++] = i;
        }
    }
    printf("%d\n",m);
    for(int i = 0;i<top;++i)
    {
        if(i)
            printf(" %d",s[i]+1);
        else printf("%d",s[i]+1);
    }
    printf("\n");

    }
    return 0;
}


