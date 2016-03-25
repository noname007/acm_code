#include<cstdio>
#include<cstring>
using namespace std;
#define M(a,b) a>b?a:b

int c[1005][1005];
int main()
{
    char a[1005],b[1005];

    int a_len,b_len;

    while(~scanf("%s%s",a,b))
    {
        a_len = strlen(a);
        b_len = strlen(b);
        c[0][0] = 0;
        for(int i= 0;i<=a_len;++i)
        {
            c[i][0] =0;
        }
        for(int j = 0;j<=b_len;++j)
        {
            c[0][j] = 0;
        }
        for(int i = 1;i<=a_len;++i)
        {
            for(int j = 1;j <=b_len;++j)
            {

                if(a[i-1] == b[j-1])
                {
                    c[i][j] =c[i-1][j-1] + 1;
                }else{
                    c[i][j] = M(c[i-1][j],c[i][j-1]);
                }
            }
        }
        printf("%d\n",c[a_len][b_len]);
    }
    return 0;
}
