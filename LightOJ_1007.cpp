#include <stdio.h>
#define N 5000000

unsigned long long phi[N+1];

void phiSieve();

int main(void)
{
    unsigned long long t,a,b,i,j,out;
    phiSieve();
    scanf("%llu",&t);
    for(i=0;i<t;i++)
    {
        scanf("%llu %llu",&a,&b);
        printf("Case %llu: %llu\n",i+1,(phi[b]-phi[a-1]));
    }

    return 0;
}

void phiSieve()
{
    unsigned long long i,j;
    for(i=2;i<=N;i++)
        phi[i]=i;
    for(i=2;i<=N;i++)
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(j=2*i;j<=N;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }

    for(i=2;i<=N;i++)
    {
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}
