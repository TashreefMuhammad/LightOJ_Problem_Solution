#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int t,n,c,i,j,k;
    scanf("%d",&t);
    for(j=0; j<t; j++)
    {
        c=0;
        scanf("%d",&n);
        long long lo,hi,mid,a[n];
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        for(i=0; i<n-2; i++)
        {
            for(k=i+1; k<n-1; k++)
            {
                lo=k+1;
                hi=n-1;
                while(lo<=hi)
                {
                    mid=(lo+hi)/2;

                    if(a[mid]>a[i]+a[k])
                        hi=mid-1;
                    else if(a[mid]<a[i]+a[k])
                        lo=mid+1;
                    else
                        break;
                }
                if(a[mid]==a[i]+a[k])
                    c+=mid-k-1;
                else
                    c+=hi-k;
            }
        }
        printf("Case %d: %d\n",j+1,c);
    }

    return 0;
}
