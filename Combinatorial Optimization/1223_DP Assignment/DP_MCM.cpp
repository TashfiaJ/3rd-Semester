#include<bits/stdc++.h>
using namespace std;

int m[100][100], s[100][100]={};


void expression(int s[][100], int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        expression(s, i, s[i][j]);
        expression(s, s[i][j]+1, j);
        cout<<")";
    }
}

int mcm(int p[], int i, int j)
{
    if(m[i][j]!=-1)
        return m[i][j];
    if(i==j)
        m[i][j]=0;
    else
    {
        m[i][j]=INT_MAX;
        for(int k=i; k<j; k++)
        {
            int q=mcm(p, i, k)+mcm(p, k+1, j)+p[i-1]*p[k]*p[j];
            if(q<m[i][j])
            {
                m[i][j]=q;
                s[i][j]=k;
            }
        }
    }
    return m[i][j];
}


int main()
{
    freopen("MCM.txt","r",stdin);
    int n;
    cout<<"Total Dimensions: ";
    cin>>n;

    cout<<"Dimensions: ";
    int p[100];
    for(int i=0; i<n; i++)
        cin>>p[i];

    //memoized version
    for(int i=1; i<n; i++)
        for(int j=0; j<n; j++)
            m[i][j]=-1;

    cout<<"Cost: "<<mcm(p, 1, n-1)<<endl;

    expression(s, 1, n-1);

}
