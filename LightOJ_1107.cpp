#include <stdio.h>
#include <string.h>

int main(void)
{
    int t,i,j,x,y,x1,y1,x2,y2,m;
    char ye[4]= {'Y','e','s','\0'};
    char no[3]= {'N','o','\0'};
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        char out[m][5];
        for(j=0; j<m; j++)
        {
            scanf("%d%d",&x,&y);
            if(x<x1||x>x2||y<y1||y>y2)
                strcpy(out[j],no);
            else
                strcpy(out[j],ye);
        }
        printf("Case %d:\n",i+1);
        for(j=0; j<m; j++)
            printf("%s\n",out[j]);
    }

    return 0;
}
