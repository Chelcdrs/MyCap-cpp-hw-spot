#include<iostream>
using namespace std;
int main(){
    int *p, arr[5];
    cout<<"Enter the elements of an array: "<<endl;
    for(int i=0; i<5; i++){
    cin>>arr[i];
    }
    p=arr;
    cout<<"You entered: "<<endl;
    for(int i=0; i<5; i++){
        cout<<*p<<endl;
        p++;
    }
    return 0;
}