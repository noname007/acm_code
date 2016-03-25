#include<cstdio>
#include<algorithm>
using namespace std;
int sum = 0;
int Cross_river(int *input,int num)
{


    if(num <= 2) return input[num-1];
    else if(num == 3)return input[0]+input[1]+input[2];
    else{
        int t1=input[0]+input[1]*2+input[num-1];
        int t2=input[0]*2+input[num-1]+input[num-2];
        int tmp=0;
        tmp = t1>t2?t2:t1;
        return Cross_river(input,num-2)+tmp;
    }
}


int main()
{
    int T_c,num,input[1005];
    scanf("%d",&T_c);
    while(T_c--)
    {
        scanf("%d",&num);
        for(int i = 0;i < num;++i)
        {
            scanf("%d",&input[i]);
        }
        sort(input,input+num);

        sum = Cross_river(input,num);
        printf("%d\n",sum);
    }

    return 0;
}
