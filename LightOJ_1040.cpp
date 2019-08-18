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

int parent[100001];

int find_parent(int node);

int main(void)
{
    int t,u,v,extra,tot_cost,cost,i,j,k,n,m,cnt;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        extra=tot_cost=0;
        scanf("%d",&n);
        grp temp;
        vector <grp> ar;
        for(i=0; i<n; i++)
            parent[i]=i;
        for(i=0; i<n; i++)
        {
            temp.from=i;
            for(k=0;k<n;k++)
            {
                scanf("%d",&u);
                if(i==k)
                    extra+=u;
                else if(u!=0)
                {
                    temp.to=k;
                    temp.weight=u;
                    tot_cost+=u;
                    ar.push_back(temp);
                }
            }
        }
        sort(ar.begin(),ar.end(),comp);
        m=ar.size();
        cost=cnt=0;
        for(i=0; i<m; i++)
        {
            u=find_parent(ar[i].from);
            v=find_parent(ar[i].to);
            if(u!=v)
            {
                parent[v]=u;
                cost+=ar[i].weight;
                cnt++;
            }
        }
        printf("Case %d: ",j+1);
        if(cnt==n-1)
            printf("%d\n",extra+tot_cost-cost);
        else
            printf("-1\n");
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
