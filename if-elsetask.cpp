#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    int age, ans;
    cout<<"Please enter your firstname: ";
    cin>>name;
    cout<<name<<"! "<<"Pretty name for a pretty person :)\n";
    cout<<"How young are you? ";
    cin>>age;
    if(age>14){
        cout<<"\nYou aren't 14 anymore so I believe you'll be able to solve the easy sum\n I'm about to present to you :)";
        cout<<"\nWhat's 8/2(2+2)? Answer quickly if you're cool :) ";
        cin>>ans;
         if(ans==16){
                    cout<<"You have not disapppinted me. Good job!\n Bye cool hooman :)";
         }
         else
                cout<<"Wrong! Shame shame shame. Please go away.";
    }   
    else
        cout<<"You're still a kid. Go play with your friends.";
return 0;
}