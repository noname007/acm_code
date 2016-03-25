#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct{
    int weight;
    int len;
}M;

int  q(int *num,int B,int E,int elem)
{
    if(B>=E) return E;
    int mid = (B+E)/2;
    if(num[mid]>elem) return q(num,mid+1,E,elem);
    else return q(num,B,mid,elem);
}

int cmp(M a,M b)
{
    if(a.weight==b.weight) return a.len<b.len;
    else return a.weight<b.weight;
}

int main()
{
    int t,num[5005];
    int tm,top = 0;
    //int input[50005];
    M input[5005];
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d",&tm);
        for(int i = 0;i<tm;++i)
            //scanf("%d",&input[i]);
            scanf("%d%d",&input[i].len,&input[i].weight);
        sort(input,input+tm,cmp);

        top = 0;
        num[0] = input[0].len;
        ++top;
        for(int i = 1; i < tm;++i)
        {
            if(input[i].len<num[top-1])
            {
                num[top++]=input[i].len;
            }else{
                num[q(num,0,top-1,input[i].len)]=input[i].len;
                //num[q(num,0,top-1,input[i])]=input[i];
            }
        }
        printf("%d\n",top);
        //system("pause");
    }
    return 0;
}
