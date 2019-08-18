#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(void)
{
    int t,i,j,l;
    string n;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>n;
        l=n.size();
        for(j=0; j<l/2; j++)
            if(n[j]!=n[l-1-j])
                break;
        printf("Case %d: ",i+1);
        if(j==l/2)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
