#include <stdio.h>
#include <math.h>

int main(void)
{
    int t,i,n,j,lies;
    double d;

    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        lies=0;
        scanf("%d",&n);
        int ar[n];
        for(j=0; j<n; j++)
        {
            scanf("%d",&ar[j]);
            if(j!=0)
            {
                if(ar[j]>ar[j-1])
                {
                    d=(double)(ar[j]-ar[j-1])/5.0;
                    d=ceil(d);
                    lies+=(int)d;
                }
            }
            else
            {
                d=(double)(ar[j]-2)/5.0;
                d=ceil(d);
                lies+=(int)d;
            }

        }
        printf("Case %d: %d\n",i+1,lies);
    }

    return 0;
}

