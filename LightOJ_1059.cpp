#include <bits/stdc++.h>

using namespace std;

typedef struct grp grp;

struct grp
{
    int from,to,weight;
};

bool comp(grp g1,grp g2)
{
    return g1.weight < g2.weight;
}

int parent[10001];

int find_parent(int node);

int main(void)
{
    int t,u,v,cost,j,n,a,tot_cost,cnt;
    long m,i;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d%ld%d",&n,&m,&a);
        grp temp;
        vector <grp> ar;
        for(i=0;i<=n;i++)
            parent[i]=i;
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&temp.from,&temp.to,&temp.weight);
            ar.push_back(temp);
        }
        sort(ar.begin(),ar.end(),comp);
        cost=cnt=0;
        for(i=0; i<m; i++)
        {
            if(ar[i].weight>=a)
                break;
            u=find_parent(ar[i].from);
            v=find_parent(ar[i].to);
            if(u!=v)
            {
                cnt++;
                parent[v]=u;
                cost+=ar[i].weight;
            }
        }
        tot_cost=cost+(n-cnt)*a;
        printf("Case %d: %d %d\n",j+1,tot_cost,n-cnt);
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
