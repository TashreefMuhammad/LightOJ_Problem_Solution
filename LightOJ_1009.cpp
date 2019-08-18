#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int cnt,set1,set2;
vector <char> col;
void DFS(int node,vector <int> grp[]);

int main(void)
{
    int t,n,i,j,k,u,v,maximum;
    scanf("%d",&t);
    map <int,int> mp;
    for(i=0;i<t;i++)
    {
        maximum=0;
        scanf("%d",&n);
        vector <int> grp[2*n+1];
        for(j=0,k=0;j<n;j++)
        {
            scanf("%d %d",&u,&v);
            if(mp.find(u)==mp.end())
                mp[u]=k++;
            if(mp.find(v)==mp.end())
                mp[v]=k++;
            grp[mp[u]].push_back(mp[v]);
            grp[mp[v]].push_back(mp[u]);
        }
        for(j=0;j<k;j++)
            col.push_back('W');
        for(j=0;j<k;j++)
            if(col[j]=='W')
            {
                cnt=set1=set2=0;
                DFS(j,grp);
                maximum+=max(set1,set2);
            }
        printf("Case %d: %d\n",i+1,maximum);
        mp.clear();
        col.clear();
    }

    return 0;
}
void DFS(int node,vector <int> grp[])
{
    col[node]='G';
    int i,l=grp[node].size();
    for(i=0;i<l;i++)
        if(col[grp[node][i]]=='W')
        {
            cnt++;
            DFS(grp[node][i],grp);
            cnt--;
        }
    if(cnt%2==0)
        set1++;
    else
        set2++;
}
