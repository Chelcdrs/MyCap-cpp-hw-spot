#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
using namespace std;
int main() {
    FILE *fp, *ft;
    char another, choice;

struct student{
        char first_name[50], last_name[50];
        char course[100];
        int section;
    };
    
    struct student e;
    char xfirst_name[50], xlast_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if(fp == NULL){
        fp=fopen("users.txt","wb+");

        if(fp==NULL){
             puts("Cannot open file");
             return 0;
        }
    }

recsize=sizeof(e);

while(1) {
    system("cls");

    cout << "\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 STUDENT INFORMATION SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
	cout <<"\n\n";
    cout<<" \n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
    cout << "\n \t\t\t  Press '1' To Add    Records";
    cout << "\n \t\t\t  Press '2' To View   Records";
    cout << "\n \t\t\t  Press '3' To Modify Records";
    cout << "\n \t\t\t  Press '4' To Remove Records";
    cout << "\n \t\t\t  Press '5' To Exit   Program";
    cout<<" \n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
    cout << "\n\n";
    cout << "\t\t\t Select Your Choice: ";
    fflush(stdin);
    choice = getche();
    switch(choice)
    {
        case '1':
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout<<"Enter the First Name : ";
                cin>>e.first_name;
                cout<<"Enter the Last Name : ";
                cin>>e.last_name;
                cout<<"Enter the Course    : ";
                cin>>e.course;
                cout<<"Enter the Section   : ";
                cin>>e.section;

                fwrite(&e,recsize,1,fp);
                cout<<"\n Add Another Record (Y/N) ";
                fflush(stdin);
                another=getchar();
            }
            break;
        case '2':
            system("cls");
           rewind(fp);
           cout<<"\xB2\xB2 View the Records in the Database \xB2\xB2 ";
           cout<<"\n";
           while(fread(&e,recsize,1,fp) == 1){
           cout<<"\n";
           cout<<"\nName     : " <<e.first_name <<" "<<e.last_name;
           cout<<"\nCourse   : " <<e.course ;
           cout<<"\nSection  : "<<e.section;
           }
           cout<<"\n\n";
           system("pause");
           break;

        case '3':
            system("cls");
            another = 'Y';
            while(another == 'Y'|| another == 'y'){
                cout<<"\n Enter the last name of the student : ";
                cin>>xlast_name;

            rewind(fp);
            while(fread(&e,recsize,1,fp) == 1)
            {
                if(strcmp(e.last_name,xlast_name) == 0)
                {
                cout<<"Enter new the Firt Name : ";
                cin>>e.first_name;
                cout<<"Enter new the Last Name : ";
                cin>>e.last_name;
                cout<<"Enter new the Course    : ";
                cin>>e.course;
                cout<<"Enter new the Section   : ";
                cin>>e.section;
                fseek(fp, - recsize, SEEK_CUR);
                fwrite(&e,recsize,1,fp);
                break;
                }
                else
                cout<<"record not found";
            }
            cout<<"\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another=getchar();
            }
            break;

        case '4':
            system("cls");
            another = 'Y';
            while(another == 'Y'|| another == 'y'){
                cout<<"\n Enter the last name of the student to delete : ";
                cin>>xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while(fread (&e, recsize,1,fp) == 1)

                if(strcmp(e.last_name,xlast_name) != 0){
                    fwrite(&e,recsize,1,ft);
                }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout<<"\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another=getchar();
            }
            break;

        case '5':
              fclose(fp);
              cout<<"\n\n";
              cout<<"\t\t\t     PROGRAM EXITED";
              cout<<"\n\n";
              exit(0);
          }
     }
return 0;
}

