
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
fstream f,fi,f1;

class Record{


   char day[20];
   char time[10];
   char meet[20];
   char task[10];
   char note[700];
   char password[10] = "group19";

public:
void ADD_RECORD();
void MODIFY_RECORD();
void VIEW_RECORD();
void DELETE_RECORD();
void EDIT_PASSWORD();
int PASSWORD();

};
int login(){
   string pass ="";
   char ch;
   cout << "\n\n\n\n\n\t\t\t\t     **************************************************";
   cout << "\n\n\n\n\n\t\t\t\t              PERSONAL DIARY MANAGEMENT SYSTEM         ";
   cout << "\n\n\n\n\n\t\t\t\t     **************************************************";
   cout << "\n\n\n\n\n\t\t\t\t\tEnter Password:";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "group19"){
      cout << "\n\n\nAccess Granted \n";
      system("pause");
      system("cls");
      int main();
   }else{
      cout << "\nAccess denied...\n";
      system("cls");
	  login();
   }
}



void Record :: ADD_RECORD()
{

    int i=0;
    system("cls");
    int count=0;
    int choice;
    Record e;
    char another ='Y';
    char time[10];
    char filename[20];
    
    cout<<"\n\n\t\t*****************************\n";
    cout<<"\t\tWELCOME TO THE ADD RECORD MENU";
    cout<<"\n\t\t******************************\n\n";
    cout<<"Enter the date of your record [DD-MM-YYYY]:";
    cin.ignore();
    cin.getline(filename,20);
    f.open(filename,ios::in|ios::binary|ios::app|ios::out);
    if(!f){
        f.open(filename,ios::in|ios::binary|ios::app|ios::out);
        if(!f)
        {
          cout<<"SYSTEM ERROR :(\n";
          cout<<"PRESS ANY KEY TO EXIT..\n";
          getch();
          return;
        }
    }
        while(another=='Y'||another=='y')
        {
            choice=0;
            if(i++>0)
            cin.ignore();
            cout<<"\n\tENTER THE TIME:[hh:mm]:";
            cin.getline(time,10);
            while(f.is_open())
            {
                if(strcmp(e.time,time)==0 && count==0)
                {
                    count++;
                    cout<<"\n\tTHE RECORD ALREADY EXISTS.\n";
                    choice=1;

                }
                count=0;
                f.close();

            }
            if(choice==0)
            {
                f.open(filename,ios::in|ios::binary|ios::app|ios::out);
                strcpy(e.time,time);
                cout<<"\tABOUT YOUR DAY:";
                cin.getline(e.day,30);
                cout<<"\tIMPORTANT MEETINGS :";
                cin.getline(e.meet,20);

                cout<<"\tTO DO TASKS FOR TOMORROW:";
                cin.getline(e.task,10);
                 cout<<"\tNOTE:";
                 cin.getline(e.note,500);
                 f.write((char*)&e,sizeof(e));
                 cout<<"\nYOUR RECORD IS ADDED...\n";
            }
            cout<<"\n\tADD ANOTHER RECORD..(Y/N)";
            another = getchar();
        }
        f.close();
        cout<<"\n\n\tPRESS ANY KEY TO EXIT..";
        getch();


    }
 

void Record :: VIEW_RECORD()
{
    system("cls");
    Record e;
    char time[10],choice,filename[14];
    int ch;
    cout<<"\n\n\t\t*************************\n";
    cout<<"\t\tWELCOME TO VIEWING MENU";
    cout<<"\n\t\t************************\n\n";
    choice=PASSWORD();
    if(choice!=0)
    {
        return ;
    }
    do{
        cout<<"\n\tENTER THE DATE OF RECORD TO BE VIEWED:[DD-MM-YYYY]:";
        cin.ignore();
        cin.getline(filename,15);
        f.open(filename,ios::in|ios::binary);
        if(!f)
        {
            puts("\nTHE RECORD DOES NOT EXIST..\n");
            cout<<"PRESS ANY KEY TO EXIT..";
            getch();
            return ;
        }

        system("cls");
        cout<<"\n\tHOW WOULD YOU LIKE TO VIEW:\n";
        cout<<"\n\t1.WHOLE RECORD OF THE DAY.";
        cout<<"\n\t2.Record of fix time.";
        cout<<"\n\t\tENTER YOUR CHOICE:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"\nTHE WHOLE RECORD FOR:"<<filename;
            while(f.read((char*)&e,sizeof(Record)))
            {
                cout<<"\n";
                cout<<"\nTIME:"<<e.time;
                cout<<"\nABOUT YOUR DAY:"<<e.day;
                cout<<"\nIMPORTANT MEETINGS:"<<e.meet;
                cout<<"\nTO DO TASKS FOR TOMORROW:"<<e.task;
                cout<<"\nNOTE:"<<e.note;
                cout<<"\n";
            }
            break;
            case 2:
            cin.ignore();
            cout<<"\nENTER TIME:[hh:mm]:";
            cin.getline(time,10);
            while(f.read((char *)&e,sizeof(e)))
            {
                if(strcmp(e.time,time)==0)
                {
                    cout<<"\nYOUR RECORD IS:";
                    cout<<"\nTIME:"<<e.time;
                    cout<<"\nABOUT YOUR DAY:"<<e.day;
                    cout<<"\nIMPORTANT MEETINGS :"<<e.meet;
                    cout<<"\nTO DO TASKS FOR TOMORROW:"<<e.task;
                    cout<<"\nNOTE:"<<e.note;
                }
            }
            break;
            default:
            cout<<"\nYOU TYPED SOMETHING ELSE...\n";
            break;
        } 
        cout<<"\n\nWOULD YOU LIKE TO CONTINUE VIEWING..(Y/N):" ;
        cin>>choice;
        f.close();
    }
    while(choice=='Y'||choice=='y');
    cout<<"\n\n\tPRESS ANY KEY TO EXIT..";
    getch();
    return ;
}

void Record :: MODIFY_RECORD()
{
    system("cls");
    Record e;
    char time[10],choice,filename[14];
    int num,count=0,count1=0;
    int pos;
    cout<<"\n\n\t\t****************************\n";
    cout<<"\t\tWELCOME TO THE MODIFYING MENU";
    cout<<"\n\t\t****************************\n\n";
    choice=PASSWORD();
    if(choice!=0)
    {
        return ;
    }
    do
    {
        cout<<"\n\tENTER THE DATE OF RECORD TO BE EDITED:[DD-MM-YYYYY]:";
        cin.ignore();
        cin.getline(filename,15);
        cout<<"\n\tENTER TIME:[hh:mm]:";
        cin.getline(time,10);
        f.open(filename,ios::binary|ios::in);
        if(!f)
        {
            cout<<"\nRECORD DOES NOT EXISTS:";
            cout<<"\nPRESS ANY KEY TO GO BACK";
            getch();
            return ;
    
        }
        while(f.read((char*)&e,sizeof(e)))
        {
            count1++;
            if(strcmp(e.time,time)==0)
            {
                cout<<"\nYOUR OLD RECORD WAS AS:";
                cout<<"\nTIME:"<<e.time;
                cout<<"\nABOUT YOUR DAY:"<<e.day;
                cout<<"\n IMPORTANT MEETINGS: "<<e.meet;
                cout<<"\nTO DO TASKS FOR TOMORROW:"<<e.task;
                cout<<"\nNOTE:"<<e.note;
                cout<<"\n\n\t\tWHAT WOULD LIKE TO EDIT..";
                cout<<"\n1.TIME";
                cout<<"\n2.ABOUT TODAY.";
                cout<<"\n3.IMPORTANT MEETINGS .";
                cout<<"\n4.TO DO TASKS FOR TOMORROW.";
                cout<<"\n5.NOTE.";
                cout<<"\n6.WHOLE RECORD.";
                cout<<"\n7.GO BACK TO MAIN MENU.";
                do{
                    cout<<"\n\tENTER YOUR CHOICE:";
                    cin>>num;
                    switch(num)
                    {
                        case 1:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nNEW TIME:[hh:mm]:";
                        cin.getline(e.time,10);
                        break;

                        case 2:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nABOUT YOUR DAY:";
                        cin.getline(e.day,20);
                        break;

                        case 3:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nANY IMPORTANT MEETINGS TOMORROW:";
                        cin.getline(e.meet,20);
                        break;

                        case 4:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nTO DO TASKS FOR TOMORROW:";
                        cin.getline(e.task,10);
                        break;

                        case 5:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nNOTE:";
                        cin.getline(e.note,500);
                        break;

                        case 6:
                        cin.ignore();
                        cout<<"\nENTER THE NEW DATA:";
                        cout<<"\nNEW TIME:[hh:mm}:";
                        cin.getline(e.time,10);
                        cout<<"\nABOUT YOUR DAY:";
                        cin.getline(e.day,30);
                        cout<<"\nANY IMPORTANT MEETINGS TOMORROW:";
                        cin.getline(e.meet,25);
                        cout<<"\nTO DO TASKS:";
                        cin.getline(e.task,10);
                        cout<<"\nNOTE:";
                        cin.getline(e.note,500);
                        break;

                        case 7:
                        cin.ignore();
                        cout<<"\nPRESS ANY KEY TO GO BACK...\n";
                        getch();
                        return ;
                        break;
                        default:
                        cin.ignore();
                        cout<<"\nYOU TYPE SOMETHING ELSE...TRY AGAIN\n";
                        break;

                    }
                }
                    while(num<1||num>8);
                        f.close();
                        f.open(filename,ios::in|ios::binary|ios::out|ios::ate);
                        int location=(count1-1)*sizeof(e);
                        f.seekp(location);
                        f.write((char *)&e,sizeof(Record));
                        f.close();
                        f.open(filename,ios::binary|ios::in);
                        f.seekp(location);
                        f.read((char*)&e,sizeof(Record));
                        choice=5;
                        break;
                    }
        
                }
                if(choice==5)
                {
                    system("cls");
                    cout<<"\n\t\t EDITING COMPLETED...\n";
                    cout<<"-------------------- \n";
                    cout<<"THE NEW RECORD IS:\n";
                    cout<<"-------------------- \n";
                    cout<<"\n TIME:"<<e.time;
                    cout<<"\n ABOUT YOUR DAY:"<<e.day;
                    cout<<"\n IMPORTANT MEETINGS:"<<e.meet;
                    cout<<"\n TO DO TASKS FOR TOMORROW:"<<e.task;
                    cout<<"\n NOTE:"<<e.note;
                    f.close();
                    cout<<"\n\n\t WOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)";
                    cin>>choice;
                    count++;}
                    else{
                        cout<<"\n THE RECORD DOES NOT EXIST::\n";
                        cout<<"\n WOULD YOU LIKE TO TRY AGAIN....(Y/N)";
                        cin>>choice;
                        f.close();
                        count1=0;
                    }
                }while (choice=='Y'||choice =='y');

            if(count==1)
            cout<<count<<"FILE IS EDITED...\n";
            else if(count>1)
            cout<<count<<"FILES ARE EDITED..\n";
            else
            cout<<"\nNO FILES EDITED...\n";
            cout<<"\tPRESS ENTER TO EXIT EDITING MENU.";
            getch();
    }
    int Record::PASSWORD()

{
	
f.open("PASS",ios::in);
f.read((char*)&password,sizeof(password));
f.close();
char pass1[15]={0},check[15]={0},ch;
int i=0,j;
cout<<"::FOR SECURITY PURPOSE::";
cout<<"::ONLY THREE TRIALS ARE ALLOWED::";
for(j=0;j<3;j++)
{
    i=0;
    cout<<"\n\n\tENTER THE PASSWORD: ";
    pass1[0]=getch();
    while(pass1[i]!='\r')
    {
        if(pass1[i]=='\b')
        {
            i--;
            cout<<"\b";
            cout<<" ";
            cout<<"\b";
            pass1[i]=getch();
        }
        else
        {
            cout<<"*";
            i++;
            pass1[i]=getch();
        }
    }
    pass1[i]='\0';
    i=0;
    if(strcmp(pass1,password)==0)
    {
        cout<<"\n\n\tACCESS GRANTED...\n";
        return 0;

    }
    else
    {
        cout<<"\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n";
    }
}
cout<<"\n\n\t::YOU ENTERED WRONG PASSWORD::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\tPRESS ANY KEY TO GO BACK...";
getch();
return 1;
}
void Record::EDIT_PASSWORD()
{
    system("cls");
    cout<<"\n";
    char pass1[15]={0},confirm[15]={0},ch;
    int choice,i,check;
    check=PASSWORD();
    if (check==1)
    {
        return;

    }
    do
    {
        if(check==0)
        {
            i=0;
            choice=0;
            cout<<"\n\n\tENTER THE NEW PASSWORD:";
            cin.ignore();
            pass1[0]=getch();
            while(pass1[i]!='\r')
            {
                if(pass1[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    pass1[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    pass1[i]=getch();
                }

            }
            pass1[i]='\0';
            i=0;
            cout<<"\n\tCONFIRM PASSWORD:";
            confirm[0]=getch();
            while(confirm[i]!='\r')
            {
                if(confirm[i]=='\b')
                {
                    i--;
                    cout<<"\b";
                    cout<<" ";
                    cout<<"\b";
                    confirm[i]=getch();
                }
                else
                {
                    cout<<"*";
                    i++;
                    confirm[i]=getch();

                }
            }
            confirm[i]='\0';
            if(strcmp(pass1,confirm)==0)
            {
                strcpy(password,pass1);
                f.open("PASS",ios::in|ios::out);
                f.seekg(0,ios::beg);
                f.write((char*)&password,sizeof(password));
                f.close();
                cout<<"\n\n\tPASSWORD CHANGED SUCCESSFULLY.";
                cout<<"\n\n\tPRESS ANY KEY TO CONTINUE...";
                getch();
                return ;

            }
            else
            {
                cout<<"\n\tTHE NEW PASSWORD DOES NOT MATCH.";
                choice=1;
            }

        }
    } while (choice==1);
    cout<<"\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...";
    getch();
}
void Record::DELETE_RECORD()
{
    system("cls");
    Record file;
    char filename[15],another = 'Y' ,time[10];
    int choice;
    int check;
    cout<<"\n\n\t\t************************\n";
    cout<<"\t\tWELCOME TO DELETE MENU";
    cout<<"\n\t\t************************\n\n";
    check = PASSWORD();
    if(check==1)
    {
        return ;
    }
    while ( another == 'Y' || another=='y')
    {
        cout<<"\n\n\tHOW WOULD YOU LIKE TO DELETE.";
        cout<<"\n\n\t-DELETE WHOLE RECORD\t\t\t[1]";
        cout<<"\n\t-DELETE A PARTICULAR RECORD BY TIME\t[2]";
    
    do
    {
        cout<<"\n\t\tENTER YOUR CHOICE:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"\n\tENTER THE DATE OF RECORD TO BE DELETED : [dd-mm--yyyy]:";
            cin.ignore();
            cin.getline(filename,15);
            f.open(filename,ios::in|ios::binary);
            if(!f)
            {
                cout<<"\nTHE FILE DOESNOT EXISTS";
                cout<<"\n PRESS ANY KEY TO GO BACK.";
                getch();
                return;
            }
            f.close();
            remove(filename);
            cout<<"\nDELETED SUCCESSFULLY...";
            break;
            case 2:
            cout<<"\n\tENTER THE DATE OF RECORD:[DD-MM-YYYY]:";
            cin.ignore();
            cin.getline(filename,15);
            f.open (filename,ios::in|ios::binary);
            if(!f)
            {
                cout<<"\nTHE FILE DOEN NOT EXISTS";
                cout<<"\nPRESS ANY KEY TO GO BACK.";
                getch();
                return;

            }
            fi.open("temp",ios::in|ios::out|ios::binary|ios::app|ios::ate);
            if(!fi)
            {
                cout<<"\nSYSTEM ERROR";
                cout<<"\nPRESS ANY KEY TO GO BACK";
                getch();
                return ;

            }
            cout<<"\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:";
            cin.getline(time,10);
            while(f.read((char*)&file,sizeof(file)))
            {
                if(strcmp(file.time,time)!=0)
                fi.write((char*)&file,sizeof(file));
            }
            f.close();
            fi.close();
            remove(filename);
            rename("temp",filename);
            cout<<"\nDELETED SUCCESSFULLY...";
            break;
        default:  
            cout<<"\n\t YOU ENTERED WRONG CHOICE";
            break;
    }

        
} while (choice<1||choice>2);
    cout<<"\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):";
    cin>>another;
}
    cout<<"\n\n\tPRESS ANY KEY TO EXIT...";
    getch();
    }



    
int main()
{
	system("color E0");
   login();
    int ch;
    Record e;
    cout<<"\n\n\t************************************\n";
    cout<<"\tPASSWORD PROTECTION PERSONAL DIARY\n";
    cout<<"\t************************************";
    while(1)
    {
        cout<<"\n\n\tMAIN MENU:";
        cout<<"\n\t-----------------\n";
        cout<<"\n\n\tADD RECORD\t[1]";
        cout<<"\n\tVIEW RECORD\t[2]";
        cout<<"\n\tMODIFY RECORD\t[3]";
        cout<<"\n\tDELETE RECORD\t[4]";
        cout<<"\n\tEDIT PASSWORD\t[5]";
        cout<<"\n\tEXIT\t\t[6]";
        cout<<"\n\n\tENTER YOUR CHOICE:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            e.ADD_RECORD();
            break;
            case 2:
            e.VIEW_RECORD();
            break;
            case 3:
            e.MODIFY_RECORD();
            break;
            case 4:
            e.DELETE_RECORD();
            break;
            case 5:
            e.EDIT_PASSWORD();
            break;
            case 6:
            cout<<"\n\n\t\tTHANK YOU!!!";
            getch();
            exit(0);
            default:
            cout<<"\nYOU ENTERED WRONG CHOICE..";
            cout<<"\nPRESS ANY KEY TO TRY AGAIN";
            getch();
            break;

        }
        system("cls");
    }
    return 0;
}   
