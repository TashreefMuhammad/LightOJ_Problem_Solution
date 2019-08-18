#include <stdio.h>
int main(void)
{
    int t,i;
    unsigned long n,c;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        c=0;
        scanf("%lu",&n);
        while(n!=0)
        {
            if(n%2==1)
                c++;
            n/=2;
        }
        printf("Case %d: ",i+1);
        if(c%2==0)
            printf("even\n");
        else
            printf("odd\n");

    }
    return 0;
}
