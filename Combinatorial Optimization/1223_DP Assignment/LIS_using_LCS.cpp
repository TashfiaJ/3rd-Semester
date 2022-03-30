#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll s1[3005], s2[3005],n;

ll dp[3005][3005];

ll lcs(ll i, ll j)
{
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll temp1=lcs(i-1, j);
    temp1=max(temp1,lcs(i, j-1));
    temp1=max(temp1,lcs(i-1, j-1)+(s1[i]==s2[j]));
    return dp[i][j]=temp1;
}

int main ()
{
   freopen("LISUsingLCS.txt","r",stdin);
   cout<<"Number of elements: ";
   cin>>n;
    for(ll i=0; i<n; i++)
    {
        cin>>s1[i];
        s2[i]=s1[i];
    }
    sort(s2, s2+n);


   for(ll i=0;i<3005; i++){
    for(ll j=0; j<3005; j++)
    {
        dp[i][j]=-1;
    }
   }

   ll lng=lcs((n-1LL), (n-1LL));
   cout<<"Longest Increasing Subsequence: "<<lng;
   ll ans[lng]={};
   ll i,j,x=lng-1;
   for(i=n-1,j=n-1;i>0&&j>0;)
   {
            //if(i-1<0)break;
           if(dp[i-1][j]==dp[i][j])i--;
           else if(j-1>=0 && dp[i][j-1]==dp[i][j])
                j--;
           else{
            ans[x]=s1[i];
            i--;
            j--;
            x--;
           }
       }

       if(x==0){if(i==0)ans[0]=s1[0];
       else
        ans[0]=s2[0];}
    cout<<"\nSequence: ";
       for(ll i=0;i<lng;i++)cout<<ans[i]<<" ";
   }


