#include <stdio.h>
#include <vector>

using namespace std;

long cnt,maximum,node;
vector <char> col;

void DFS(long num,vector <long> edge[], vector <long> weight[]);
void DFS2(long num,vector <long> edge[], vector <long> weight[]);

int main(void)
{
    long t,i,n,j,k,u,v,w;
    scanf("%ld",&t);
    for(i=0; i<t; i++)
    {
        scanf("%ld",&n);
        maximum=0;
        vector <long> edge[n],weight[n];
        for(j=0; j<n-1; j++)
        {
            scanf("%ld %ld %ld",&u,&v,&w);
            edge[u].push_back(v);
            edge[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }
        for(k=0; k<n; k++)
            col.push_back('W');
        cnt=0;
        DFS(0,edge,weight);
        col.clear();
        for(k=0; k<n; k++)
            col.push_back('W');
        cnt=maximum=0;
        DFS(node,edge,weight);
        col.clear();
        printf("Case %ld: %ld\n",i+1,maximum);
    }

    return 0;
}
void DFS(long num,vector <long> edge[], vector <long> weight[])
{
    col[num]='G';
    bool f=true;
    long i,l=edge[num].size();
    for(i=0; i<l; i++)
        if(col[edge[num][i]]=='W')
        {
            f=false;
            cnt+=weight[num][i];
            DFS(edge[num][i],edge,weight);
            cnt-=weight[num][i];
        }
    if(f && cnt>maximum)
    {
        maximum=cnt;
        node=num;
    }
}
