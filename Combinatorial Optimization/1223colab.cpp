#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100
int totalCountry;
int totalEdge;
int index;
int capacity[N];
int traverseRate[N][N];
int resGraph[N][N],parent[N];
string source, sink;
map<string,int>countryCode;
int maxflow=0;
bool vis[N];

bool bfs()
{
    queue<int>q;
    q.push((int)countryCode[source]);
    memset(parent, 0, sizeof(parent));
    memset(vis, false, sizeof(vis));
    parent[countryCode[source]]=-1;
    vis[countryCode[source]]=true;

    while(!q.empty())
    {
        int peek=q.front();
        q.pop();
        for(int i=0;i<totalCountry;i++)
        {
            if(resGraph[peek][i]>0 &&vis[i]==false)
            {
                if(i==countryCode[sink]){

               parent[i]=peek;
               return true;
            }
            q.push(i);
            parent[i]=peek;
            vis[i]=true;

        }
    }

}
return false;

}
int fordFulkerson()
{
  memset(parent, -1, sizeof(parent));
  //parent[countryCode[source]]=0;

  while(bfs())
  {
      int tempMin=INT_MAX;
     for(int i=countryCode[sink];i!=countryCode[source];i=parent[i])
     {
         int u=parent[i];
         tempMin = min(tempMin,resGraph[u][i]);
     }
    for(int i=countryCode[sink];i!=countryCode[source];i=parent[i])
     {
         int u=parent[i];
         resGraph[u][i]-=tempMin;
         resGraph[i][u]+=tempMin;
     }
     cout<<"Residual Graph: \n";
     for(int i=0;i<totalCountry;i++)
     {
         for(int j=0;j<totalCountry;j++)
         {
             cout << resGraph[i][j]<<" ";
         }
          cout <<'\n';
     }

     maxflow+=tempMin;
  }
  return maxflow;
}

int main()
{
    // freopen("ff.txt","r",stdin);
    cin >> totalCountry >> totalEdge;
    memset(traverseRate, 0, sizeof(traverseRate));
    memset(resGraph, 0, sizeof(resGraph));


    index=0;
    string country;
    ll tempCapacity;
    cout<<"Enter country name: ";
    for(int i=0;i<totalCountry;i++)
    {
        cin >> country;
        countryCode[country]=index;
        index++;
    }
    cout<<"Enter capacity: ";
    for(int i=0;i<totalCountry;i++)
    {
        cin >> country >> tempCapacity;
        capacity[countryCode[country]]=tempCapacity;
    }
    cout<<"Enter the traverse rate from country a to country b: ";

    for(int i=0;i<totalEdge;i++)
    {
        string countryA, countryB;
        int rate;
        cin >> countryA >> countryB >> rate;
        traverseRate[countryCode[countryA]][countryCode[countryB]]=rate;
        resGraph[countryCode[countryA]][countryCode[countryB]]=min(rate, capacity[countryCode[countryB]]);
    }

         cout<<"Residual Graph: \n";
     for(int i=0;i<totalCountry;i++)
     {
         for(int j=0;j<totalCountry;j++)
         {
             cout << resGraph[i][j]<<" ";
         }
          cout <<'\n';
     }

    cin >> source >> sink;
    int ans = fordFulkerson();
    cout<<ans;



}
