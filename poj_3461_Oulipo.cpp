#include<cstdio>
#include<cstring>
using namespace std;

void get_next(char p[],int next[])
{
        int len = strlen(p);
        int i = 0,k = 0;

        memset(next,0,sizeof(next));
        if(p[1] == p[0])next[1] = 0;
        for(int j = 0;j <len;++j)
        {
            if(p[j+1] == p[k]){
                    next[j+1] = next[k];
                    ++j;
                    ++k;
            }else{
                next[j+1] = k;
            }
        }
        return ;
}


int kmp(char tx[],char p[],int next[])
{
    int len_t = strlen(tx);
    int len_p = strlen(p);
    int j = 0,i = 0;
    get_next(p,next);
    for(i  = 0; i < len_t && j < len_p;)
    {
        if(tx[i] == p[j])
        {
            ++j;
            ++i;
        }else{
            j = next[j];
            if(j == 0)
                ++i;
        }
    }
    if(j == len_p) return i - j;
    else return -1;
}


int main()
{
    int t;
    char p[10005],ts[1000001];
    int next[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",p,ts);
        kmp(ts,p,next);
    }

    return 0;
}
