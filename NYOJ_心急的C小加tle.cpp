#include<cstdio>
#include<algorithm>
#define Max(a,b) a<b?b:a
using namespace std;
typedef struct{
    int weight;
    int len;
}M;

int cmp(M a,M b)
{
    return a.weight<b.weight;
}

int main()
{
    int t,num[5005];
    M input[5005];

    scanf("%d",&t);
    while(t--)
    {
        int tm,l =0;
        scanf("%d",&tm);
        for(int i = 0;i<tm;++i)
            scanf("%d%d",&input[i].weight,&input[i].len);
        sort(input,input+tm,cmp);
        for(int i = 0; i< tm;++i)
        {
            num[i] = 1;
            for(int j = 0; j < i;++j)
            {
                if(input[i].len<input[j].len)
                {
                    num[i] = Max(num[i],num[j]+1);
                }
            }
            l = Max(l,num[i]);
        }
        printf("%d\n",l);
    }
    return 0;
}
