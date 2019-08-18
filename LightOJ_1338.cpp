#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int t,i,l,j,lexo1,lexo2;
    char s1[101],s2[101];
    scanf("%d",&t);
    getchar();
    for(i=0; i<t; i++)
    {
        lexo1=lexo2=0;
        gets(s1);
        gets(s2);
        l=strlen(s1);
        for(j=0; j<l; j++)
        {
            if(s1[j]!=' ')
                lexo1+=tolower(s1[j]);
        }
        l=strlen(s2);
        for(j=0; j<l; j++)
        {
            if(s2[j]!=' ')
                lexo2+=tolower(s2[j]);
        }
        if(lexo1==lexo2)
            printf("Case %d: Yes\n",i+1);
        else
            printf("Case %d: No\n",i+1);
    }
    return 0;
}

