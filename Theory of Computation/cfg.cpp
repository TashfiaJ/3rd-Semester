#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin>>s;
    //s1 = cfg(s);
    
    string s1 = "E";
    for(int i=0;i<s.length();i++){
        if(s[i] == '0'){
            s.replace(i,1,s1); 
        }
        
         if(s[i] == '1'){
             s.replace(i,1,s1); 
        }
        cout << s << endl;
        
    }
    
    
    for(int i=0;i<s.length();i++){
        
         if(s[i] == 'E' && s[i+1] == '+' && s[i+2] == 'E'){
             s.replace(i,3,s1); 
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i] == 'E' && s[i+1] == '*' && s[i+2] == 'E'){
           s.replace(i,3,s1); 
        }
        
        if(s[i] == '(' && s[i+1] == 'E' && s[i+2] == ')'){
            s.replace(i,3,s1); 
        }
        cout<< s << endl;
    }
    
    if(s == "E"){
        cout << "accepted" << endl;
    }
    
    else{
        for(int i=0;i<s.length();i++){
        if(s[i] == 'E' && s[i+1] == '+' && s[i+2] == 'E'){
           cout << "accepted" << endl;
           break;
        }
        
        else if(s[i] == 'E' && s[i+1] == '*' && s[i+2] == 'E'){
           cout << "accepted" << endl;
           break;
        }
        
        else if(s[i] == '(' && s[i+1] == 'E' && s[i+2] == ')'){
            cout << "accepted" << endl;
            break;
        }
        
        else{
        cout << "Rejected\n";
        break;
        }
    }
    }
    
}
