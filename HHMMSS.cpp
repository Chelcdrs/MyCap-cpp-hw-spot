#include<iostream>
#include<iomanip>
using namespace std;
class time{
    private:
        int hour, minute, second;
    public:
        enter();
        cal(){
        	int total;
        	total=(hour*3600)+(minute*60)+(second*1);
        	return total;
		};
        result();
};
time::enter(){
        cout<<"Enter time:\n";
        cout<<"Hours? ";
        cin>>hour;
        cout<<"\nMinute? ";
        cin>>minute;
        cout<<"\nSecond? ";
        cin>>second;
}
time::result(){
		cout<<"\nTime= "<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second;
		cout<<"\nTime in total seconds: "<<cal();
}

int main(){
	time t;
	t.enter();
	t.cal();
	t.result();
}
