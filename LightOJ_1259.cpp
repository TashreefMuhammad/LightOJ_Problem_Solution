#include <stdio.h>
#include <vector>

using namespace std;

bool dp[10000001];
vector <int> prime;
void sieve();
int main(void)
{
    int t,n,i,j,sum=0;
    sieve();
    scanf("%d",&t);
    for(j=0; j<t; j++)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0; prime[i]+prime[i]<=n; i++)
        {
            if(dp[n-prime[i]]==false)
                sum++;
        }
        printf("Case %d: %d\n",j+1,sum);
    }
    return 0;
}
void sieve()
{
    int i,j;
    dp[0]=dp[1]=true;
    for(i=4; i<=10000000; i+=2)
        dp[i]=true;
    for(i=3; i*i<=10000000; i+=2)
        if(dp[i]==false)
            for(j=i*i; j<=10000000; j+=2*i)
                dp[j]=true;
    for(i=2; i<9999999; i++)
        if(dp[i]==false)
            prime.push_back(i);
}
