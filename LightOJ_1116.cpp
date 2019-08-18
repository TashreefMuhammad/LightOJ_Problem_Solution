#include <stdio.h>

int main(void)
{
    long long t,i,j,w;
    scanf("%lld",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lld",&w);
        if(w%2!=0)
            printf("Case %lld: Impossible\n",i+1);
        else
        {
            j=w/2;
            while(j%2==0)
                j/=2;
            printf("Case %lld: %lld %lld\n",i+1,j,w/j);
        }
    }

    return 0;
}
