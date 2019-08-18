#include <stdio.h>
int main(void)
{
    int a,b,t,i;
    scanf("%d",&t);
    int ans[t];
    for(i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        ans[i]=a+b;
    }
    for(i=0;i<t;i++)
        printf("Case %d: %d\n",i+1,ans[i]);
    return 0;
}
