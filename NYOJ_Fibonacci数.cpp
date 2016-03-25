#include<cstdio>
using namespace std;
int main()
{
    int a[30];
    a[1]=1;
    a[2]=1;
    for(int i=3;i < 21;++i)
    {
        a[i]=a[i-1]+a[i-2];
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int m;
        scanf("%d",&m);
        printf("%d\n",a[m]);
    }
    return 0;
}
