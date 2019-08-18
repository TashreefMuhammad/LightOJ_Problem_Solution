#include <stdio.h>
#include <math.h>

int main(void)
{
    int t,i;
    double x,y,c,lo,hi,mid,a,b,temp;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lf %lf %lf",&x,&y,&c);
        lo=0.0;
        if(x>y)
            hi=x;
        else
            hi=y;
        while(1)
        {
            mid=(lo+hi)/2;
            a=sqrt(x*x-mid*mid);
            b=sqrt(y*y-mid*mid);
            temp=((a*b)/(a+b));
            if(temp>c)
                lo=mid;
            else
                hi=mid;
            if(fabs(temp-c)<.00000000001)
                break;
        }
        printf("Case %d: %.10lf\n",i+1,lo);
    }

    return 0;
}
