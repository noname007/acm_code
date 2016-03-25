#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define Swap(a,b) a+=b; b = a-b;a -= b
#define Min(a,b) a<b?1:0
using namespace std;


//加入一个节点后维护一棵树；
void insert_node(int *input,int loc)
{

    int parent = loc/2;
    while(parent != 0)
    {
        if(input[parent] <= input[loc])
        {
            break;
        }else{
            Swap(input[parent],input[loc]);
            loc = parent;
            parent /= 2;
        }
    }
    return ;
}


//删除一个节点后,维护一棵树
void del_node(int *input,int n)
{
    int loc = 1,left = 2*loc,right = 2*loc + 1;
    input[loc] = input[n--];
    int t;
    //while(loc < n && left <=n)
    while(left <= n)
    {
        if(right <=n){
            t = Min(input[left],input[right]);
            t = (t== 1)?left:right;
        }else{
            t = left;
        }
        if(input[loc] > input[t])
        {
            Swap(input[loc],input[t]);
            loc = t;
        }else{
            break;
        }
        left = 2 * loc;
        right = 2 * loc + 1;
    }
    return ;
}


int main()
{
    int N;
    int input[10010];
    scanf("%d",&N);

    memset(input,0,sizeof(input));
    for(int i = 1;i < N+1;++i)
    {
        scanf("%d",&input[i]);

        insert_node(input,i);
    }
    long long tmp = 0,s = 0;
    while(N>1)
    {
        tmp = input[1];
        del_node(input,N);
        --N;
        tmp += input[1];
        del_node(input,N);
        input[N] = tmp;
        insert_node(input,N);
        s += tmp;
    }
    printf("%lld\n",s);
    return 0;
}
