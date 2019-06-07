/****
    * Problem ID        : LightOJ 1133
    * Problem Name      : Array Simulation
    * Required Topics   : Brute Force
****/

//Simple brute force approach
//Note : Carefully read problem statement. Or you may get presentation error.

#include <iostream>

using namespace std;

int main(void)
{
    int t,i,j,k,n,m,b,d,temp;
    char c;

    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        int ar[n];

        for(j=0;j<n;j++)
            cin>>ar[j];

        for(j=0;j<m;j++)
        {
            cin>>c;

            if(c=='S')
            {
                scanf("%d",&b);
                for(k=0;k<n;k++)
                    ar[k]+=b;
            }
            else if(c=='M')
            {
                scanf("%d",&b);
                for(k=0;k<n;k++)
                    ar[k]*=b;
            }
            else if(c=='D')
            {
                scanf("%d",&b);
                for(k=0;k<n;k++)
                    ar[k]/=b;
            }
            else if(c=='R')
            {
                for(k=0;k<n/2;k++)
                {
                    temp=ar[k];
                    ar[k]=ar[n-1-k];
                    ar[n-1-k]=temp;
                }
            }
            else if(c=='P')
            {
                scanf("%d %d",&b,&d);
                swap(ar[b],ar[d]);
            }

        }

        printf("Case %d:\n",i+1);
        printf("%d",ar[0]);
        for(j=1;j<n;j++)
            printf(" %d",ar[j]);
        printf("\n");
    }

    return 0;
}

