#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("Coin.txt","r",stdin);
    int m, n, a[100], i , j;
    //m=Total Value
    //n=number of coins
    cin>>m>>n;

    //Infinite supply of coins
    for(i=0; i<n; i++)
        cin>>a[i];

    int ans[m+1];
    ans[0]=0;
    for(i=1; i<=m; i++)
        ans[i]=INT_MAX;

    for(i=1; i<=m; i++)
        for(j=0; j<m; j++)
        {
            if(a[j]<=i)
            {
                int x=ans[i-a[j]];
                if(x!=INT_MAX && x+1<ans[i])
                    ans[i]=x+1;
            }
        }

    if(ans[m]==INT_MAX)
        cout<<"No solution!";
    else
        cout<<"Minimum coins required: "<<ans[m];
}
