#include<cstdio>
#include<cstdlib>
using namespace std;
long long sum = 0;
int c[100010];
void inversion(int a[],int b,int e)
{
    int mid = (b+e)/2;
    if(b+1>= e)return;

    inversion(a,b,mid);
    inversion(a,mid,e);
    int i = b,j = mid,k= b;
    for(;i < mid && j <e;++k)
    {
        if(a[i] < a[j])
        {
            c[k] = a[i];
            ++i;
        }else{
            c[k] = a[j];
            sum += mid - i;
            ++j;
        }
    }
    while(i < mid){
        c[k++] = a[i++];
    }
    while(j < e)
    {
        c[k++] = a[j++];
    }
    for(int i = b; i<e;++i) a[i] = c[i];
    return;
}


int main()
{
    int N = 100000;
    int a[100010];
    for(int i = 0;i <N;++i)
    {
        scanf("%d",&a[i]);
    }
    sum = 0;
    inversion(a,0,N);
    printf("%lld\n",sum);
    system("pause");
}
