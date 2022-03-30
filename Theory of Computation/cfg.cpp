#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    for(ll i=0;i<n;i++)
    {
        if(s[i]=='0'|| s[i]=='1')s[i]='E';
    }
    ll brk=0,flag=1;
    for(ll i=0;i<n;)
    {
        cout << i << " ";
        if(s[i]=='E')
        {
            if(s[i+1]=='*'||s[i+1]=='+'){
                if(s[i+2]=='E'){
                    if(i+2>=n){
                        flag=0;
                        break;
                    }
                    i+=3;
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
             else if(s[i+1]==')')
            {
                if(brk>0){brk--;i+=2;s[i+1]='E';continue;}
                else
                {
                    flag=0;
                    break;
                }
            }

            else if(s[i+1]=='(')
            {
                brk++;
                i+=2;
            }
        }
        else if(s[i]=='('){
            brk++;
            i++;
            if(i==n){
                flag=0;
                break;
            }
           }
            else if(s[i]==')'){
                if(brk>0){
                    brk--;
                    s[i]='E';
                    if(i==n-1){
                    i++;}
                    continue;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            else {
                flag=0;
                break;
            }

    }
    if(brk>0)flag=0;
    if(flag){
        cout<<"Accepted";
    }
    else
    {
        cout<<"Not Accepted";
    }
}
