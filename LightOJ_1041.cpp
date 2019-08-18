#include <bits/stdc++.h>

using namespace std;

typedef struct grp grp;

struct grp
{
    string from,to;
    int weight;
};

bool comp(grp g1,grp g2)
{
    return g1.weight < g2.weight;
}

int parent[51];

int find_parent(int node);

int main(void)
{
    int t,u,v,cost,i,j,k,m,cnt;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d",&m);
        grp temp;
        vector <grp> ar;
        map <string,int> mp;
        for(i=0,k=0; i<m; i++)
        {
            cin>>temp.from>>temp.to>>temp.weight;
            if(mp.find(temp.from)==mp.end())
            {
                mp[temp.from]=k++;
                parent[k-1]=k-1;
            }
            if(mp.find(temp.to)==mp.end())
            {
                mp[temp.to]=k++;
                parent[k-1]=k-1;
            }
            ar.push_back(temp);
        }
        sort(ar.begin(),ar.end(),comp);
        cost=cnt=0;
        for(i=0; i<m; i++)
        {
            u=find_parent(mp[ar[i].from]);
            v=find_parent(mp[ar[i].to]);
            if(u!=v)
            {
                parent[v]=u;
                cost+=ar[i].weight;
                cnt++;
            }
        }
        printf("Case %d: ",j+1);
        if(cnt==k-1)
            printf("%d\n",cost);
        else
            printf("Impossible\n");
    }

    return 0;
}
int find_parent(int node)
{
    if(parent[node]==node)
        return node;
    else
        return parent[node]=find_parent(parent[node]);
}
