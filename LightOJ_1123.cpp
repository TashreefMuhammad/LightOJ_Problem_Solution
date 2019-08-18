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
    int t,u,v,cost,j,n,w,cnt,i,k,m,st;
    scanf("%d",&t);
    for(j=0; j<t; j++)
    {
        m=0;
        scanf("%d%d",&n,&w);
        grp ar[w];
        printf("Case %d:\n",j+1);
        while(w--)
        {
            scanf("%d %d %d",&ar[m].from,&ar[m].to,&ar[m].weight);
            m++;
            for(k=1; k<=n; k++)
                parent[k]=k;
            sort(ar,ar+m,comp);
            cost=cnt=0;
            st=m;
            for(k=0; k<st; k++)
            {
                u=find_parent(ar[k].from);
                v=find_parent(ar[k].to);
                if(u!=v)
                {
                    cnt++;
                    parent[v]=u;
                    cost+=ar[k].weight;
                }
                else
                    ar[k]=ar[--m];
            }
            if(cnt==n-1)
                printf("%d\n",cost);
            else
                printf("-1\n");
        }

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
