#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
static int p=0;
class a{
    private:
        char busno[5], arrival[10], depart[10], from[20], to[20], seat[8][4][10];
    public:
        void install();
        void reserve();
        void empty();
        void show();
        void pos(int i);
}bus[10];

void vline(char ch){
    for(int i=80; i>0; i--)
        cout<<ch;
}
void a::install(){
    cout<<"\nEnter bus No.: ";
    cin>>bus[p].busno;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture time: ";
    cin>>bus[p].depart;
    cout<<"\nFrom: ";
    cin>>bus[p].from;
    cout<<"\nTo: ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
    cout<<"\n\nBus Information added!\n";
    system("pause");
    system("cls");
}
void a::reserve(){
    int seat;
    char num[5];
    top:
    cout<<"\nEnter Bus No.: ";
    cin>>num;
    int n;
    for(n=0;n<=p;n++){
        if(strcmp(bus[n].busno, num)==0)
        break;
    }
    while(n<=p){
        cout<<"\nSeat No.: ";
        cin>>seat;
        if(seat>32){
            cout<<"\nThere are only 32 seats available in this bus.";
        }
        else{
            if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0){
                cout<<"\nEnter passenger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            }
            else
                cout<<"\nThe seat number is already reserved.";
        }
    }
    if(n>p){
        cout<<"\nPlease enter correct bus No.";
        goto top;
    }
	system("pause");
	system("cls");   
}
void a::empty(){
    for(int i=0; i<8; i++){
        for(int j=0; j<4; j++){
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}
void a::show(){
    int n;
    char num[3];
    cout<<"\nEnter bus No.: ";
    cin>>num;
    cout<<endl;

    for(n=0;n<=p;n++){
        if(strcmp(bus[n].busno, num)==0)
        break;
    }
    while(n<=p){
        vline('*');
        cout<<"\nBus No.: \t"<<bus[n].busno<<"\t\tArrival time: "<<bus[n].arrival<<"\tDeparture time: "<<bus[n].depart<<endl<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<bus[n].to<<endl;
        vline('*');
        bus[0].pos(n);
        int a=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<4;j++){
                a++;
                if(strcmp(bus[n].seat[i][j], "Empty")!=0)
                cout<<"\nThe seat number "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        cout<<"\n\nPlease press 'ENTER' to go the main page.";
        break;
    }
    if(n>p)
    cout<<"\nEnter correct bus No.: ";
}
void a::pos(int l){
    int s=0; p=0;
    for(int i=0;i<8;i++){
        cout<<endl;
        for(int j=0;j<4;j++){
            s++;
            if(strcmp(bus[l].seat[i][j], "Empty")==0){
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
                p++;
            }
            else{
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
            }
        }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in bus No.: "<<bus[l].busno;
}
int main(){
    int w;
    while(1){
        cout<<"\n\n";
        cout<<"********************* MRS. TRUSFRATED's BUS SERVICES *********************";
        cout<<"\n\n";
        cout<<"                      1. Available bus numbers\n";
        cout<<"                      2. Install\n";
        cout<<"                      3. Reservation\n";
        cout<<"                      4. Show Reservation Information\n";
        cout<<"                      5. Exit\n";
        cout<<"                      Enter your choice: ";
        cin>>w;

        switch(w){
            case 1: cout<<"\n***************AVAILABLE BUS NUMBERS***************"<<endl;
            cout<<"\n******* 1. 316                     ******* 5. 236"<<endl;
            cout<<"\n******* 2. 324                     ******* 6. 256"<<endl;
            cout<<"\n******* 3. 124                     ******* 7. 235"<<endl;
            cout<<"\n******* 4. 238                     ******* 8. 306"<<endl;
            cout<<"\n***************************************************"<<endl; 
            system("pause");
            system("cls");
            
            break;

            case 2: bus[p].install(); break;

            case 3: bus[p].reserve(); break;

            case 4: bus[0].show(); getch(); break;

            case 5: exit(0);

            default: cout<<"Oops! Seems like you've entered something wrong.";
        }
    }
    return 0;
}

