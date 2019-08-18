#include <stdio.h>

bool possible(int key,int n,int m,int c[]);

int main(void)
{
    int t,n,m,i,j,lo,hi,mid,ans,tot_c;
    scanf("%d",&t);
    j=0;
    while(++j<=t)
    {
        scanf("%d %d",&n,&m);
        int c[n];
        tot_c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            tot_c+=c[i];
        }
        lo=0;
        hi=tot_c;
        while(lo<=hi)
        {
            mid=(lo+hi)>>1;
            if(possible(mid,n,m,c))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        printf("Case %d: %d\n",j,ans);
    }
    return 0;
}

bool possible(int key,int n,int m,int c[])
{
    //printf("key %d\n",key);
    int i,rem=key,tmp=0,cnt=0;
    for(i=0;i<n;i++)
    {
        if(rem>c[i])
            rem-=c[i];
        else if(rem==c[i])
        {
            rem=key;
            cnt++;
        }
        else if(c[i]>key)
            break;
        else
        {
            rem=key-c[i];
            cnt++;
        }
        if(cnt>m)
            break;
    }
    if(i==n)
    {
        if((cnt==m && rem==key)||cnt<m)
            return true;
        else
            return false;
    }
    else
        return false;
}
