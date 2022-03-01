#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll input_length(string w){

    int i=0,l=0;
    while(w[i]!='\0'){
        l++;
        i++;
    }
    return l;
}

int main ()
{
    cout << "Enter total no of state: ";

    ll state;

    cin >> state;

    ll start, final_no;

    cout << "Enter the start state: ";

    cin >> start;

    start--;

    cout << "How many final states are there? ";

    cin >> final_no;

    cout << "Enter the final states: ";

    ll FINAL[final_no];

    for(ll i=0;i<final_no;i++)
    {
        ll v;

        cin >> v;

        FINAL[i]=v-1;
    }


    //Transition Table
    cout << "\nInput TRANSITION TABLE:\n";

    ll table[state][2];

    for(ll i=0; i<state; i++)
    {
        ll x;

        cout << "From state " << i+1 << " with input '0' " << "goes to state -> ";

        cin >> x;

        table[i][0] = x-1;

        cout<< "From state " << i+1 << " with input '1' " << "goes to state -> ";

        cin >> x;

        table[i][1] = x-1;
    }

    cout << "\n\t------------------------------------------------------------------------------\n\n";

    cout << "Enter the string: ";

    string input;

    cin >> input;

    cout << "\n\t------------------------------------------------------------------------------\n\n";

    ll current_state = start;

    ll length = input_length(input);

    for(ll i=0; i<length; i++)
    {
        cout << "state "<< current_state+1 << " with input " << input[i]-48 << " to -> " << table[current_state][input[i]-48]+1 << '\n';

        current_state = table[current_state][input[i]-48];
    }

    //string check
    ll flag=0;

    for(ll i=0;i<final_no;i++)
    {
        if(current_state == FINAL[i])
        {
            flag=1;

            break;
        }
    }

    if(flag)
    {
        cout << "\tAccepted\n";
    }

    else
    {
        cout << "\tNot Accepted\n";
    }
}
