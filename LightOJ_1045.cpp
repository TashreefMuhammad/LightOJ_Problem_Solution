#include <stdio.h>
#include <math.h>

double dp[1000001];

void digit();

int main(void)
{
    int t,n,b,i;
    digit();
    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        scanf("%d %d",&n,&b);
        printf("Case %d: %d\n",i+1,(int)(dp[n]/log(b))+1);
    }

    return 0;
}

void digit()
{
    int i;
    for(i=1; i<=1000000; i++)
        dp[i]=log(i)+dp[i-1];
}
