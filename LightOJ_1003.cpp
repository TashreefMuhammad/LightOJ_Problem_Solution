#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector <char> color;
map <string,int> node_num;
bool f;

void DFS(int num,vector <int> grp[]);

int main(void)
{
    int i,j,t,m,k,l;
    string name,child;
    cin>>t;
    for(i=0; i<t; i++)
    {
        f=false;
        cin>>m;
        vector <int> grp[2*m+1];
        for(j=0,k=0; j<m; j++)
        {
            cin>>name>>child;
            if(node_num.find(name)==node_num.end())
                node_num[name]=k++;
            if(node_num.find(child)==node_num.end())
                node_num[child]=k++;
            grp[node_num[name]].push_back(node_num[child]);
        }
        for(j=0; j<k; j++)
            color.push_back('W');
        for(j=0; j<k && f==false; j++)
            if(color[j]=='W')
                DFS(j,grp);
        printf("Case %d: ",i+1);
        if(f)
            printf("No\n");
        else
            printf("Yes\n");
        node_num.clear();
        color.clear();
    }
    return 0;
}

void DFS(int num,vector <int> grp[])
{
    int i,l=grp[num].size();
    color[num]='G';
    for(i=0; i<l && f==false; i++)
    {
        if(color[grp[num][i]]=='W')
            DFS(grp[num][i],grp);
        else if(color[grp[num][i]]=='G')
        {
            f=true;
            break;
        }
    }
    color[num]='B';
}
