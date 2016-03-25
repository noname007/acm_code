#include <cstdio>
#include <algorithm>
using namespace std ;

typedef struct
{
	int v,w;
}input_me;
input_me a_me[1000010];
bool cmp(input_me a,input_me b)
{
	return double(a.v)/a.w > double(b.v)/b.w;
}
int main(int argc, char const *argv[])
{

	int N,W;
	while(~scanf("%d%d",&N,&W))
	{
            for(int i = 0; i < N;++i)
		{
			scanf("%d%d",&(a_me[i].v),&(a_me[i].w));
		}
		sort(a_me,a_me+N,cmp);
        double sum = 0;
		for(int i = 0;i < N;++i)
        {
            if(a_me[i].w < W)
            {
                W-= a_me[i].w;
                sum += a_me[i].v;
            }else{
                sum += double(W)*a_me[i].v/a_me[i].w;
                break;
            }
        }
        printf("%.3f\n",sum);
	}
	return 0;
}
