#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main(int argc, char const *argv[])
{
	int N;
	int weight[10010];
	//while()
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&weight[i]);
	}
    long  sum = 0,tmp;
    for(int i = N-1;i > 0;--i){
        sort(weight,weight+i+1,cmp);
        tmp= weight[i] + weight[i-1];
        weight[i-1] = tmp;
        sum += tmp;
    }
    printf("%ld\n",sum);
	return 0;
}
