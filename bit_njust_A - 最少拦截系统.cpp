#include<stdio.h>
#include<stdlib.h>
using namespace std;
int  q(int *num,int B,int E,int elem)
{
    if(B>=E) return E;
    int mid = (B+E)/2;
    if(num[mid]<elem) return q(num,mid+1,E,elem);
    else return q(num,B,mid,elem);
}

int main()
{
    int t,num[10005];
    int tm,top = 0;
    int input[10005];
    //scanf("%d",&t);
    while(~scanf("%d",&tm))
    {

        for(int i = 0;i<tm;++i)
            scanf("%d",&input[i]);
        top = 0;
        num[0] = input[0];
        ++top;
        for(int i = 1; i < tm;++i)
        {
            if(input[i]>num[top-1])
            {
                num[top++]=input[i];
            }else{
                num[q(num,0,top-1,input[i])]=input[i];
            }
        }
        printf("%d\n",top);
    }
    return 0;
}
