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

int max_parent[10001],min_parent[10001];

int find_max_parent(int node);
int find_min_parent(int node);

int main(void)
{
    int t,i,j,n,u,v,m,max_cost,min_cost,out;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d",&n);
        grp temp;
        vector <grp> max_ar,min_ar;
        for(i=0; i<=n; i++)
            max_parent[i]=min_parent[i]=i;

        while(1)
        {
            scanf("%d %d %d",&temp.from,&temp.to,&temp.weight);
            if(temp.from==0 && temp.to==0 && temp.weight==0)
                break;
            max_ar.push_back(temp);
            min_ar.push_back(temp);
        }
        sort(max_ar.begin(),max_ar.end(),comp);
        sort(min_ar.begin(),min_ar.end(),comp);
        m=max_ar.size();
        max_cost=min_cost=0;

        for(i=0; i<m; i++)
        {
            u=find_min_parent(min_ar[i].from);
            v=find_min_parent(min_ar[i].to);

            if(u!=v)
            {
                min_parent[v]=u;
                min_cost+=min_ar[i].weight;
            }
            u=find_max_parent(max_ar[m-1-i].from);
            v=find_max_parent(max_ar[m-1-i].to);
            if(u!=v)
            {
                max_parent[v]=u;
                max_cost+=max_ar[m-1-i].weight;
            }
        }
        out=max_cost+min_cost;
        printf("Case %d: ",j+1);
        if(out%2==0)
            printf("%d\n",out/2);
        else
        {
            int r=__gcd(out,2);
            printf("%d/%d\n",out/r,2/r);
        }
    }

    return 0;
}
int find_max_parent(int node)
{
    if(max_parent[node]==node)
        return node;
    else
        return max_parent[node]=find_max_parent(max_parent[node]);
}
int find_min_parent(int node)
{
    if(min_parent[node]==node)
        return node;
    else
        return min_parent[node]=find_min_parent(min_parent[node]);
}
