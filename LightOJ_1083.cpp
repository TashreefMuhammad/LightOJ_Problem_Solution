#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,i,j,k,top,temp,maximum;
    stack <int> st;
    cin>>t;
    for(k=0;k<t;k++)
    {
        maximum=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;)
        {
            if(st.empty()||a[st.top()]<=a[i])
                st.push(i++);
            else
            {
                top=st.top();
                st.pop();
                temp=a[top];
                if(st.empty())
                    temp*=i;
                else
                    temp*=(i-st.top()-1);
                if(temp>maximum)
                    maximum=temp;
            }
        }
        while(!st.empty())
        {
            top=st.top();
            st.pop();
            temp=a[top];
            if(st.empty())
                temp*=i;
            else
                temp*=i-st.top()-1;
            if(temp>maximum)
                maximum=temp;
        }
        cout<<"Case "<<k+1<<": "<<maximum<<"\n";
    }

    return 0;
}
