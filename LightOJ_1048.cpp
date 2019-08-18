#include <stdio.h>

bool possible(int val,int k,int n,int loc[]);

int main(void)
{
    int t,n,j,k,i,lo,hi,mid,dist,cnt,ans;
    scanf("%d",&t);
    j=0;
    while(++j<=t)
    {
        scanf("%d %d",&n,&k);
        n++;
        int loc[n];
        for(i=0;i<n;i++)
            scanf("%d",&loc[i]);
        lo=0;
        hi=1000000;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(possible(mid,k,n,loc))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %d\n",j,ans);
        for(i=cnt=dist=0; i<n; i++)
        {
            if(dist+loc[i]>ans)
            {
                printf("%d\n",dist);
                cnt++;
                dist=loc[i];
            }
            else if(dist+loc[i]==ans)
            {
                printf("%d\n",dist+loc[i]);
                dist=0;
                cnt++;
            }
            else if(n-i-1==k-cnt)
            {
                printf("%d\n",dist+loc[i]);
                dist=0;
                cnt++;
            }
            else
                dist+=loc[i];
        }
    }

    return 0;
}

bool possible(int val,int k,int n,int loc[])
{
    int i,cnt,dist;
    dist=0;
    cnt=0;
    for(i=dist=cnt=0; i<n; i++)
    {
        if(loc[i]>val)
            return false;
        if(dist+loc[i]>val)
        {
            cnt++;
            dist=loc[i];
        }
        else if(dist+loc[i]==val)
        {
            cnt++;
            dist=0;
        }
        else
            dist+=loc[i];
    }
    if(dist>0)
        cnt++;
    if(cnt<=k+1)
        return true;
    else
        return false;
}
