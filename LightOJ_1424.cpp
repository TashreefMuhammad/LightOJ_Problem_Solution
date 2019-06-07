/****
    * Problem ID        : LightOJ 1424
    * Problem Name      : New Land
    * Required Topics   : Maximum area of histogram (2D)
****/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int m,n;
int area(int a[]);

int main(void)
{
    int i,j,t,k,maximum;
    string s;

    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        scanf("%d %d",&m,&n);
        int mat[m][n];
        for(i=0;i<m;i++)
        {
            cin>>s;
            for(j=0;j<n;j++)
            {
                //For ease of calculation, we take '0' for the lands we can't use, '1' otherwise
                //So, we convert the input here.
                //Rest of the program is designed to solve it this way
                if(s[j]=='1')
                    mat[i][j]=0;
                else
                    mat[i][j]=1;
            }
        }

        //The idea here is to start from top row of the 2D area. Find the maximum area in that row.
        //Store that maximum area, move on to the next row.
        //However, on the next row, every index who doesn't have 0, will add the value in it's previous
        //row with itself, otherwise it remains 0. Then run the algorithm for finding max area in a
        //histogram on it. Note that, we actually are creating unique histograms on every row and trying
        //to find maximum sum from all of it.

        //Finding area from the first row.
        maximum=area(mat[0]);

        //Moving down the rows and searching for the maximum area as explained above.
        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
                if(mat[i][j])
                    mat[i][j]+=mat[i-1][j];
            maximum=max(maximum,area(mat[i]));
        }

        printf("Case %d: %d\n",k+1,maximum);
    }

    return 0;
}

//A function that finds maximum area in 1D histogram
int area(int a[])
{
    stack <int> st;
    int i,top,temp,maximum=0;
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
    return maximum;
}
