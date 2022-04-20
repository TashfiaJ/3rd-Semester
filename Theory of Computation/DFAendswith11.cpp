// L = {w | w is a set of string that ends with 11}

#include<bits/stdc++.h>
using namespace std;

int current_state=1;

int w_length(string w){

    int i=0,l=0;
    while(w[i]!='\0'){
        l++;
        i++;
    }
    return l;
}

void A(char c)
{
    int ps=current_state;

    if(c == '1')
        current_state = 2;
    else if(c =='0')
        current_state = 1;
    else
        current_state = -1;

    if(current_state != -1)
        cout<< "T(q" << ps << ", " << c << ")=>q" << current_state << endl;
}

void B(char c)
{
    int ps=current_state;
    if(c=='1')
        current_state=3;
    else if(c=='0')
        current_state=1;
    else
        current_state=-1;
    if(current_state!=-1)
        cout<<"T(q"<<ps<<", "<<c<<")=>q"<<current_state<<endl;
}

void C(char c)
{
    int ps=current_state;
    if(c=='1')
        current_state=3;
    else if(c=='0')
        current_state=1;
    else
        current_state=-1;
    if(current_state!=-1)
        cout<<"T(q"<<ps<<", "<<c<<")=>q"<<current_state<<endl;
}

void DFA(string w)
{
    for(int i=0; i<w_length(w); i++)
    {
        if(current_state==1)
            A(w[i]);
        else if(current_state==2)
            B(w[i]);
        else if(current_state==3)
            C(w[i]);
        else
        {
            cout<<"Invalid string\n";
            return;
        }
    }

    if(current_state==3)cout<<"\nACCEPTED";

    else cout<<"\nREJECTED";
        return;
}
int main()
{
    string w;
    cout<<"Enter string: ";
    cin>>w;
    DFA(w);

}
