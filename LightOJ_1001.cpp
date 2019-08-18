#include <stdio.h>
int main(void)
{
    int a,t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        if(a<=10)
            printf("0 %d\n",a);
        else
            printf("10 %d\n",a-10);
    }
    return 0;
}
