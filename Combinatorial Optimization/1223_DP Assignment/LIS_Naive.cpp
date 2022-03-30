#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll a[3005],dp[3005];

ll lis (ll i)
{
    if(i==0)return dp[i]=1;
    if(dp[i]!=-1)return dp[i];
    ll ans=1;
    for(ll j=0;j<i;j++)
    {
        if(a[j]<a[i]){
            ans=max(ans, lis(j)+1);
        }
    }
    return dp[i]=ans;
}
int main()
{
   freopen("LISNaive.txt","r",stdin);
   cout<<"Enter no of elements: ";
   cin >> n;
   for(ll i=0; i<n;i++)dp[i]=-1;
   for(ll i=0; i<n; i++)cin >> a[i];
   ll ans=1;
   for(ll i=n-1;i>=0;i--){
    ans=max(ans,lis(i));
   }
   cout<<"Length of LIS: "<<ans<<endl;

   //sequence print
   cout<<"Sequence: ";
   ll sequence[ans];
   ll lng=ans,idx=ans-1,mx=INT_MAX;
   for(ll i=n-1;i>=0;i--){
    if(dp[i]==lng && a[i]<=mx){
        sequence[idx]=a[i];
        mx=a[i];
        lng--;
        idx--;
    }
    if(lng==0)break;
   }
   for(ll i=0;i<ans;i++)cout<<sequence[i]<<" ";
}
