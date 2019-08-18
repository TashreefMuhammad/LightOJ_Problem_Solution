#include <stdio.h>
#include <math.h>

int main(void)
{
    int i,t,flag,d1,d2,d3,d4,b1,b2,b3,b4,checker,power;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        flag=0;
        scanf("%d.%d.%d.%d",&d1,&d2,&d3,&d4);
        scanf("%d.%d.%d.%d",&b1,&b2,&b3,&b4);
        checker=0;
        power=1;
        while(b1!=0)
        {
            checker+=(b1%10)*power;
            b1/=10;
            power*=2;
        }
        if(checker!=d1)
            flag=1;
        checker=0;
        power=1;
        while(b2!=0&&flag==0)
        {
            checker+=(b2%10)*power;
            b2/=10;
            power*=2;
        }
        if(checker!=d2&&flag==0)
            flag=1;
        checker=0;
        power=1;
        while(b3!=0&&flag==0)
        {
            checker+=(b3%10)*power;
            b3/=10;
            power*=2;
        }
        if(checker!=d3&&flag==0)
            flag=1;
        checker=0;
        power=1;
        while(b4!=0&&flag==0)
        {
            checker+=(b4%10)*power;
            b4/=10;
            power*=2;
        }
        if(checker!=d4&&flag==0)
            flag=1;
        if(flag==1)
            printf("Case %d: No\n",i+1);
        else
            printf("Case %d: Yes\n",i+1);
    }

    return 0;
}
