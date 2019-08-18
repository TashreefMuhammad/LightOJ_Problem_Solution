#include <stdio.h>

int main(void)
{
    int t,i,n,d,sum;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        sum=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&d);
            if(d>0)
                sum+=d;
        }
        printf("Case %d: %d\n",i+1,sum);
    }

    return 0;
}


