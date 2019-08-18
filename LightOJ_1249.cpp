#include <stdio.h>
#include <string.h>

int main(void)
{
    int t,i,j,n,l,w,h,thief,victim,maximum,minimum;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        char name[n][21];
        int volume[n];
        for(j=0; j<n; j++)
        {
            scanf("%s %d %d %d",&name[j],&l,&w,&h);
            volume[j]=l*w*h;
        }
        printf("Case %d: ",i+1);
        if(n==2)
        {
            if(volume[0]==volume[1])
                printf("no thief\n");
            else
            {
                if(volume[0]>volume[1])
                    printf("%s took chocolate from %s\n",name[0],name[1]);
                else
                    printf("%s took chocolate from %s\n",name[1],name[0]);
            }
        }
        else if(n==3)
        {
            if(volume[0]==volume[1]&&volume[1]==volume[2])
                printf("no thief\n");
            else
            {
                if(volume[0]>volume[1]&&volume[0]>volume[2])
                {
                    if(volume[1]<volume[2])
                        printf("%s took chocolate from %s\n",name[0],name[1]);
                    else
                        printf("%s took chocolate from %s\n",name[0],name[2]);
                }
                else if(volume[1]>volume[0]&&volume[1]>volume[2])
                {
                    if(volume[0]<volume[2])
                        printf("%s took chocolate from %s\n",name[1],name[0]);
                    else
                        printf("%s took chocolate from %s\n",name[1],name[2]);
                }
                else
                {
                    if(volume[0]<volume[1])
                        printf("%s took chocolate from %s\n",name[2],name[0]);
                    else
                        printf("%s took chocolate from %s\n",name[2],name[1]);
                }
            }
        }
        else
        {
            maximum=0;
            minimum=1000001;
            for(j=0; j<n; j++)
            {
                if(volume[j]>maximum)
                {
                    thief=j;
                    maximum=volume[j];
                }
                if(volume[j]<minimum)
                {
                    victim=j;
                    minimum=volume[j];
                }
            }
            if(maximum==minimum)
                printf("no thief\n");
            else
                printf("%s took chocolate from %s\n",name[thief],name[victim]);
        }
    }

    return 0;
}
