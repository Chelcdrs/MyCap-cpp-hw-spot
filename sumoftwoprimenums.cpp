#include<iostream>
using namespace std;
int prime(int n);
int prime0(int n);
int main(){
    int num;
    cout<<"Please enter a number: ";
    cin>>num;
    for(int i=2; i<=num-i; i=prime(i)){
        if(prime0(num-i)){
            cout<<num<<" = "<<i<<" + "<<num-i<<endl;
        }
    }
    return 0;
}
int prime(int n){
    do{
        n++;
        }while(!prime0(n));
    return n;
}
int prime0(int n){
    int i;
    for(i=2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
