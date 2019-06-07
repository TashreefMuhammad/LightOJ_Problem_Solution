/****
    * Problem ID        : LightOJ 1301
    * Problem Name      : Monitoring Processes
    * Required Topics   : Greedy (Interval Scheduling)
****/

//The solution of this problem is the direct implementation of
//Greedy algorithm "Interval Scheduling"
#include <bits/stdc++.h>

using namespace std;

struct routine{
    int stat,val;
}c[100001];

bool cmp(routine a,routine b)
    {
        if(a.val==b.val)
            return a.stat<b.stat;
        else
            return a.val<b.val;
    }

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long t,i,n,j,ans,out,a,b,k;

    cin>>t;
    int fin[t];

    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0,k=0;j<n;j++)
        {
            cin>>a>>b;
            c[k].val=a;
            c[k++].stat=0;
            c[k].val=b;
            c[k++].stat=1;
        }
        sort(c,c+k,cmp);
        ans=0;
        out=-1;
        for(j=0;j<k;j++)
        {
            if(!c[j].stat)
                ans++;
            else
                ans--;
            if(ans>out)
                out=ans;
        }
        fin[i]=out;
    }
    for(i=0;i<t;i++)
        cout<<"Case "<<i+1<<": "<<fin[i]<<endl;
    return 0;
}
