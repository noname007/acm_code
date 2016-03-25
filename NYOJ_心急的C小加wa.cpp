#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct{
    int weight;
    int len;
}M;

int  q(int *num,int B,int elem)
{

}

int cmp(M a,M b)
{
    return a.weight<b.weight;
}

int main()
{
    int t,num[50005];
    int tm,top = 0;
    M input[50005];
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&tm);
        for(int i = 0;i<tm;++i)
            scanf("%d%d",&input[i].weight,&input[i].len);
        sort(input,input+tm,cmp);

        top = 1;
        num[1] = input[0].len;
        ++top;
        for(int i = 1; i < tm;++i)
        {
            if(input[i].len<num[top-1])
            {
                num[top++]=input[i].len;
            }else if(num[i]!=input[i].len){
                num[q(num,top-1,input[i].len)]=input[i].len;
            }
        }

        printf("%d\n",top);
    }
    return 0;
}
