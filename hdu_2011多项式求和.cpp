#include<cstdio>
int main()
{
    int c,t,f;
    scanf("%d",&c);
    double sum = 0;
    for(int j = 0;j < c;++j)
    {
        sum = 0;
        f= 1;
        scanf("%d",&t);
        for(int i = 1;i<=t;++i)
        {
            sum += 1/double((i*f));
            f *= -1;
        }
        printf("%.2f\n",sum);
    }
}
