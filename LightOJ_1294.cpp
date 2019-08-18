#include <stdio.h>

int main(void)
{
    long int i,t,n,m;
    scanf("%ld",&t);
    for(i=0; i<t; i++)
    {
        scanf("%ld%ld",&n,&m);
        printf("Case %ld: %ld\n",i+1,(n*m)/2);
    }

    return 0;
}
