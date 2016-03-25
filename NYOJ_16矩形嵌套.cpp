#include<cstdio>
#include<algorithm>
using namespace std;
#define S(a,b) a^=b; b^=a; a^=b
#define MAX(a,b) a>b?a:b
typedef struct{
    int a,b;
}rec;

int cmp(rec A,rec B)
{
    return A.b<B.b;
}


int main()
{
    int test,num[1005];
    rec input_rec[1005];

    scanf("%d",&test);
    while(test--)
    {
        int tmp,m=0;
        scanf("%d",&tmp);
        for(int i= 0; i < tmp; ++i)
        {
            scanf("%d%d",&input_rec[i].a,&input_rec[i].b);
            if(input_rec[i].a >input_rec[i].b)
            {
                S(input_rec[i].a,input_rec[i].b);
            }
        }
        sort(input_rec,input_rec+tmp,cmp);

        for(int i = 0;i<tmp;++i)
        {
            num[i] =1;
            for(int j = 0;j<i;++j)
            {
                if(input_rec[i].a >input_rec[j].a&&input_rec[i].b>input_rec[j].b)
                    num[i] = MAX(num[i],num[j]+1);
            }
            if(m<num[i])m=num[i];
        }
        printf("%d\n",m);
    }

    return 0;
}
