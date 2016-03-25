#include <stdio.h>
#include <string.h>

int q(char *input,int begin,int end,char elem)
{
	if(begin >= end) return end;
	int mid = (begin+end)/2;
	if(input[mid] < elem) return q(input,mid+1,end,elem);
	else return q(input,begin,mid,elem);
}

int main(int argc, char const *argv[])
{
	int t,top,l;
	char input[10010],s[10010];
	scanf("%d",&t);
	while(t--)
	{

		scanf("%s",input);
		top = 1;
		s[0]=input[0];

		for(int i = 1;i<strlen(input);++i)
		{
			if(s[top-1] < input[i]){
				s[top++] = input[i];
			}else{
			    l=q(s,0,top-1,input[i]);
				s[l] = input[i];
			}
		}

		printf("%d\n",top);
	}

	return 0;
}
