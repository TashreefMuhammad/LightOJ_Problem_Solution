#include <stdio.h>

int main(void)
{
    int t,i,p,l,time;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        time=19;
        scanf("%d %d",&p,&l);
        if(p>l)
            time+=4*(p-l);
        else
            time+=4*(l-p);
        time+=4*p;
        printf("Case %d: %d\n",i+1,time);
    }

    return 0;
}
