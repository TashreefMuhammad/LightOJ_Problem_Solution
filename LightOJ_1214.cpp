#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int t,i,j;
    long long b,reminder;
    string a;
    cin>>t;
    for(i=0; i<t; i++)
    {
        cin>>a>>b;
        reminder=0;
        int l=a.size();
        if(b<0)
            b*=-1;
        if(a[0]=='-')
            j=1;
        else
            j=0;
        while(j<l)
        {
            reminder=reminder*10+(a[j]-'0');
            reminder=reminder%b;
            j++;
        }
        if(reminder)
            cout<<"Case "<<i+1<<": not divisible"<<endl;
        else
            cout<<"Case "<<i+1<<": divisible"<<endl;
    }

    return 0;
}
