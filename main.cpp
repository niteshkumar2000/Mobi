#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<cstdio>
#include<iomanip>
#include<fstream>
#include<cmath>

using namespace std;

struct Time{
    int hour,min,sec;
};

//struct time;

struct Date{
    int day,month,year;
};

//struct date;

class Wi_fi{

    static bool status;
    static int count;
    string passwd;
    string name;

public:

    Wi_fi(){
        cout<<"Wi-Fi connection"<<endl;
        count++;
    }

    void set_wi_fi(){
        cout<<"Enter the name"<<endl;
        cin>>name;
        cout<<"Enter the password"<<endl;
        cin>>passwd;
    }//passwd verification

    void set_status(){

         if(status == true){
            status = false;
            cout<<"Wi-Fi is OFF"<<endl;
         }
         else{
            string x;
            cout<<"Enter the security password"<<endl;
            cin>>x;
            if(x==passwd){
                cout<<"Connecting to "<<name<<endl;
                status = true;
                cout<<"Wi-Fi is ON"<<endl;
            }
         }
    }//set value on or off

    static bool getcount(){
        return count;
    }

};

bool Wi_fi :: status = false;
int Wi_fi :: count = -1;

//static members to keep all values as same for all objects also verify passwd

class Bluetooth{

    static bool status;

public:

    Bluetooth(){
        cout<<"Bluetooth connection"<<endl;
    }

    void set_status(){

         if(status == true){
            status = false;
            cout<<"Bluetooth is OFF"<<endl;
         }
         else{
            status = true;
            cout<<"Bluetooth is ON"<<endl;
         }
    }

};

bool Bluetooth :: status = false;
//blutooth settings

class Flash_light{

    static bool status;


public:

    Flash_light(){
        cout<<"Flash Light connection"<<endl;
    }

    void set_status(){

         if(status == true){
            status = false;
            cout<<"Flash Light is OFF"<<endl;
         }
         else{
            status = true;
            cout<<"Flash Light is ON"<<endl;
         }
    }

};
//flash light on or off

bool Flash_light :: status = false;

class Hotspot{

    static bool status;

public:

    Hotspot(){
        cout<<"Hotspot connection"<<endl;
    }

    void set_status(){

         if(status == true){
            status = false;
            cout<<"Hotspot is OFF"<<endl;
         }
         else{
            status = true;
            cout<<"Hotspot is ON"<<endl;
         }
    }

};

bool Hotspot :: status = false;
//Hotspot on or off;

class Battery_saver{

    static bool status;

public:

    Battery_saver(){
        cout<<"Battery saver connection"<<endl;
    }

    void set_status(){

         if(status == true){
            status = false;
            cout<<"Battery saver is OFF"<<endl;
         }
         else{
            status = true;
            cout<<"Battery saver is ON"<<endl;
         }
    }

};

bool Battery_saver :: status = false;
//less than 15 acticvate battery saver

class Sim;

class Data{

    static bool status;
    static bool slot;

public:

    Data(){
        //cout<<"Data connection"<<endl;
    }

    void set_status(){
         cout<<"Data connection"<<endl;
         if(status == true){
            status = false;
            cout<<"Data is OFF"<<endl;
         }
         else{
            status = true;
            cout<<"Data is ON"<<endl;
         }
    }
    friend class Sim;
};

bool Data :: status = false;
bool Data :: slot = false;
//mobile data changes to sim1 and 2;
class Sim{

    string name;
    static bool status;
    Data d1;

public:

    Sim(){
       //cout<<"Sim settings"<<endl;
    }

    void create(){
        cout<<"Enter the SIM name"<<endl;
        cin>>name;
    }

    void set_slot(){
        cout<<"Sim settings"<<endl;
         if(status == true){
            status = false;
            d1.slot = false;
            cout<<"Sim slot 1 is active"<<endl;
         }
         else{
            status = true;
            d1.slot = true;
            cout<<"Sim slot 2 is active"<<endl;
         }
    }


};

bool Sim :: status = false;
//change sim slot to 1 and 2;
class Volume{

    static int value;

public:

    Volume(){
        cout<<"Volume"<<endl;
    }

    void operator ++ (int){

            value++;
            if(value>10){
                cout<<"Limit exceeded"<<endl;
                value = 10;
            }
            cout<<"Volume set to level "<<value<<endl;

    }

    void operator -- (int){
        value--;
        if(value < 0){
            value=0;
        }
        cout<<"Volume set to level "<<value<<endl;
    }

    void reset(){
        value = 0;
        cout<<"Volume set to level "<<value<<endl;
    }

    void operator () (int n,bool mode){
        if(mode == true){
            value += n;
            if(value>10){
                cout<<"Limit exceeded"<<endl;
                value = 10;
            }
            cout<<"Volume set to level "<<value<<endl;
        }
        else if(mode == false){
            value-=n;
            if(value < 0){
                value=0;
            }
            cout<<"Volume set to level "<<value<<endl;
        }
    }

};
//volume increase or rapid;

int Volume :: value = 0;

class Brightness{

    static int value;

public:

    Brightness(){
        cout<<"Brightness"<<endl;
    }

    void operator ++ (int){
        value++;
        if(value>10){
            cout<<"Limit exceeded"<<endl;
            value = 10;
        }
        cout<<"Brightness set to level "<<value<<endl;
    }

    void operator -- (int){
        value--;
        if(value < 0){
            value = 0;
        }
        cout<<"Brightness set to level "<<value<<endl;
    }

    void reset(){
        value = 0;
        cout<<"Brightness set to level "<<value<<endl;
    }

    void operator () (int n,bool mode){
        if(mode == true){
            value += n;
            if(value>10){
                cout<<"Limit exceeded"<<endl;
                value = 10;
            }
            cout<<"Brightness set to level "<<value<<endl;
        }
        else if(mode == false){
            value-=n;
            if(value < 0){
                value=0;
            }
            cout<<"Brightness set to level "<<value<<endl;
        }
    }
};

int Brightness :: value = 0;

//Brightness increase or rapid;

class Settings;

class Battery{

    static int value;

public:

    Battery(){
        //cout<<"Battery"<<endl;
    }

    void operator -- (int){
        value--;
        if(value<15){
            Battery_saver b1;
            b1.set_status();
        }
    }

    void show_status(){
        cout<<"Your battery percentage is "<<value<<endl;
    }

};

int Battery :: value = 100;

class Security{

    static string passwd;
    static int pin;
    static bool flag;

    template <typename t>
    t validate(){
            t x,y;
            l1:cout<<"Enter the password"<<endl;
            cin>>x;
            cout<<"Re-enter the password"<<endl;
            cin>>y;

            if(x==y){
                return x;
            }
            else{
                cout<<"Wrong passwd \nRe-enter the passwd"<<endl;
                goto l1;
            }
        }

public:

    Security(){
        cout<<"Security Zone"<<endl;
        flag = false;
    }

    void create(){
        int n;

        cout<<"Enter the mode of login\n1.Password 2.PIN"<<endl;
        cin>>n;

        if(n==1){
            passwd = validate<string>() ;
        }
        else if(n==2){
            pin = validate<int>();
        }

        flag =  true;
    }

    void verify(){
        string  x;
        int n,y;

        cout<<"Enter the mode of login\n1.Password 2.PIN"<<endl;
        cin>>y;


        if(y==1){

               l1:
                cout<<"Enter the passwd"<<endl;
                cin>>x;


                if(x == passwd){
                    cout<<"Verified"<<endl;
                }
                else{
                    cout<<"Access denied!!!  retry"<<endl;
                    goto l1;
                }
        }
        else if(y==2){

            l2:
                cout<<"Enter the passwd"<<endl;
                cin>>n;


                if(n == pin){
                    cout<<"Verified"<<endl;
                }
                else{
                    cout<<"Access denied!!!  retry"<<endl;
                    goto l2;
                }
        }
    }

    void change_passwd(){
        create();
    }

    static bool getflag(){
        return flag;
    }

};
//create and verify passwd
class Clock{

    Time t1;
    Date d1;

public:

    Clock(){
        cout<<"Clock"<<endl;
    }

    void display_time(){

        time_t now = time(0);

        tm* timePtr = localtime(&now);

        t1.hour = timePtr->tm_hour;
        t1.min = timePtr->tm_min;
        t1.sec = timePtr->tm_sec;

        cout << "Time     " <<t1.hour<<":"<<t1.min<<":"<<t1.sec<< endl;
    }

    void display_date(){
        time_t now = time(0);

        tm* timePtr = localtime(&now);

        d1.day = timePtr->tm_mday;
        d1.month = timePtr->tm_mon+1;//month is from 0 to 11
        d1.year = timePtr->tm_year+1900; //year since 1900

        cout << "Date     " <<d1.day<<"/"<<d1.month<<"/"<<d1.year<< endl;
    }

    void set_timer(){
        int n;
        cout<<"Enter the no. of seconds"<<endl;
        cin>>n;
        cout<<"Count down starts\n"<<endl;

        for(int i=n;i>=0;i--){
            cout<<i<<" \r";
            Sleep(1000);
        }
        for(int i=0;i<3;i++)
            Beep(1000,600);

        cout<<"\n\nTime up!!!!"<<endl;
    }
};
//showing time date and timer

string Security :: passwd = "\0";
int Security :: pin = 0;
bool Security :: flag = false;

class Settings{

    Battery s1;
    Security s2;

public:

    Settings(){
        cout<<"Welcome to settings"<<endl;
    }

    void Selection(){

        int n;
        string x;

        do{

            cout<<"Enter the operations to be done"<<endl;
            cout<<"1.Wi-Fi"<<endl;
            cout<<"2.Bluetooth"<<endl;
            cout<<"3.Flash_light"<<endl;
            cout<<"4.Hotspot"<<endl;
            cout<<"5.Battery Saver"<<endl;
            cout<<"6.Data Connection"<<endl;
            cout<<"7.Change Sim slot for data connection"<<endl;
            cout<<"8.Increase brightness"<<endl;
            cout<<"9.Increase volume"<<endl;
            cout<<"10.Decrease brightness"<<endl;
            cout<<"11.Decrease volume"<<endl;
            cout<<"12.Security"<<endl;

            cin>>n;

            switch(n){
                case 1: {
                            Wi_fi v1;
                            if(v1.getcount() == 0)
                                v1.set_wi_fi();
                            v1.set_status();
                            s1--;
                            break;
                        }

                case 2: {
                            Bluetooth b1;
                            b1.set_status();
                            s1--;
                            break;
                        }

                case 3: {
                            Flash_light f1;
                            f1.set_status();
                            s1--;
                            break;
                        }

                case 4: {
                            Hotspot h1;
                            h1.set_status();
                            s1--;
                            break;
                        }

                case 5: {
                            Battery_saver bat1;
                            bat1.set_status();
                            s1--;
                            break;
                        }

                case 6: {
                            Data d1;
                            d1.set_status();
                            s1--;
                            break;
                        }

                case 7: {
                            Sim si1;
                            si1.set_slot();
                            s1--;
                            break;
                        }

                case 8: {
                            Brightness b1;
                            int z;

                            cout<<"How would you like to increase \n1.Single 2.Rapid"<<endl;
                            cin>>z;

                            if(z==1){
                                b1++;
                            }
                            else{
                                int y;
                                cout<<"Enter the level"<<endl;
                                cin>>y;
                                b1(y,true);
                            }
                            s1--;
                            s1--;
                            break;
                        }

                case 9: {
                            Volume v1;
                            int c;

                            cout<<"How would you like to increase \n1.Single 2.Rapid"<<endl;
                            cin>>c;

                            if(c==1){
                                v1++;
                            }
                            else{
                                int y;
                                cout<<"Enter the level"<<endl;
                                cin>>y;
                                v1(y,true);
                            }
                            s1--;
                            break;
                        }

                case 10: {
                            Brightness b1;
                            int z;

                            cout<<"How would you like to decrease \n1.Single 2.Rapid"<<endl;
                            cin>>z;

                            if(z==1){
                                b1--;
                            }
                            else{
                                int y;
                                cout<<"Enter the level"<<endl;
                                cin>>y;
                                b1(y,false);
                            }
                            s1--;
                            s1--;
                            break;
                        }

                case 11: {
                            Volume v1;
                            int c;

                            cout<<"How would you like to decrease \n1.Single 2.Rapid"<<endl;
                            cin>>c;

                            if(c==1){
                                v1--;
                            }
                            else{
                                int y;
                                cout<<"Enter the level"<<endl;
                                cin>>y;
                                v1(y,false);
                            }
                            s1--;
                            break;
                        }

                case 12:{
                            int i;

                            if(s2.getflag() == false)
                                s2.create();

                            cout<<"Enter the option \n1.Verify 2.Change password"<<endl;
                            cin>>i;

                            if(i==1)
                                s2.verify();
                            else if(i==2)
                                s2.change_passwd();

                            break;
                        }

                default: cout<<"Wrong option"<<endl;
            }

            cout<<"Do you want to continue\nyes or no"<<endl;
            cin>>x;

            system("CLS");

        }while(x == "yes");

        s1.show_status();

    }

};
//all the above things are engaged here;
class Calculator {
private:
    float a;
    float b;
public:
    Calculator ()
    { a = b = 0; }

    float add (float a, float b){ return a + b; }

    float subtract (float a, float b){ return a - b; }

    float divide (float a, float b){ return a / b; }

    float multiply (float a, float b){ return a * b; }

    float root(float a,float b=0){return sqrt(a);}
};
//to perform calculation
class phoneBook{
    char name[20],phno[15];
public:
    void getdata();
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};
//maintaining record
void phoneBook :: getdata(){
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}
//method 1
void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}
//method 2
class Contacts{
public:
    void list(){

    phoneBook rec;
    fstream file;
    file.open("phone.txt", ios::ate | ios::in | ios::out | ios::binary);
    char ch,nm[20],telno[6];
    int choice,found=0,choose=1;

    while(choose){

        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Dial a number. \n";
        cout<<"7) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice){
            case 1 :
                rec.getdata();
                cin.get(ch);
                file.write((char *) &rec, sizeof(rec));
                break;

            case 2 :
                file.seekg(0,ios::beg);
                cout<<"\n\nRecords in Phone Book\n";
                while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                        rec.showdata();
                }
                file.clear();
                break;

            case 3 :{
                cout<<"\n\nEnter Name : ";
                cin>>nm;
                file.seekg(0,ios::beg);
                found=0;
                while(file.read((char *) &rec, sizeof(rec)))
                {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        rec.showdata();
                        string no;
                        no=rec.getname();
                        cout<<endl<<"Dialing....... \t "<<no<< endl;
                    }
                }
                file.clear();
                if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                break;

            case 4 :
                cout<<"\n\nEnter Telephone No : ";
                cin>>telno;
                file.seekg(0,ios::beg);
                found=0;
                while(file.read((char *) &rec, sizeof(rec)))
                {
                    if(strcmp(telno,rec.getphno())==0)
                    {
                        found=1;
                        rec.showdata();
                        string no;
                        no=rec.getname();
                        cout<<endl<<"Dialing....... \t "<<no<< endl;
                    }
                }
                file.clear();
                if(found==0)
                    cout<<"\n\n---Record Not found---\n";

                break;
                }

            case 5 : {

                cout<<"\n\nEnter Name : ";
                cin>>nm;
                file.seekg(0,ios::beg);
                found=0;
                int cnt=0;
                while(file.read((char *) &rec, sizeof(rec)))
                {
                    cnt++;
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        break;
                    }
                }
                file.clear();
                if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                else
                {
                    int location = (cnt-1) * sizeof(rec);
                    cin.get(ch);
                    if(file.eof())
                        file.clear();

                    cout<<"Enter New Telephone No : ";
                    cin>>telno;
                    file.seekp(location);
                    rec.update(nm,telno);
                    file.write((char *) &rec, sizeof(rec));
                    file.flush();
                }
                break;
            }
            case 6:{
                Sim s1;
                int op;
                cout<<"Enter Sim slot 1.slot 1 2.slot 2"<<endl;
                cin>>op;

                if(op == 2){
                        s1.set_slot();
                }

                string no;
                cout<<"Enter the number \t";
                cin>>no;
                cout<<"Dialing "<<no<<endl;
            }
            case 7 : choose=0;
        }
    }
    file.close();

    }
};
//Contact add,perform updation
class Message{
public:
    void text(){

    phoneBook rec;
    fstream file;
    file.open("contact.txt", ios::in );
    char ch,nm[20];
    int choice,found=0,choose=1;
    while(choose){

        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Display All Records\n";
        cout<<"2) Message to a user\n";
        cout<<"3) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice){
            case 8:
                rec.getdata();
                cin.get(ch);
                file.write((char *) &rec, sizeof(rec));
                break;

            case 1 :
                file.seekg(0,ios::beg);
                cout<<"\n\nRecords in Phone Book\n";
                while(file){
                    file.read((char *) &rec, sizeof(rec));
                    if(!file.eof())
                        rec.showdata();
                }
                file.clear();
                break;

            case 2 :
                cout<<"\n\nEnter Name : ";
                cin>>nm;
                file.seekg(0,ios::beg);
                found=0;
                while(file.read((char *) &rec, sizeof(rec)))
                {
                    if(strcmp(nm,rec.getname())==0)
                    {
                        found=1;
                        char data[100];
                        rec.showdata();
                        string x;
                        ofstream outfile;
                        outfile.open("m.txt",ios::app);
                        cout <<endl<< "Writing to the file" << endl;
                        cout << "Enter";
                        getline(cin,x);
                        cout << " your message: ";
                        cin >> data;
                        cin.ignore();

                        outfile << data << endl;

                        outfile.close();
                    }
                }
                file.clear();
                if(found==0)
                    cout<<"\n\n---Record Not found---\n";
                break;
            case 3 :
                choose=0;
                break;
        }
    }
    file.close();
    }
};
//messaging from contacts
class APP{
    string name;
};
//gemeric class as app;

struct node{
    int priority;
    string info;
    struct node *link;
};
//struct for node
class Priority_Queue{
private:
    node *front;
public:
    Priority_Queue()
    {
        front = NULL;
    }

    void insert(string item, int priority)
    {
        node *tmp, *q;
        tmp = new node;
        tmp->info = item;
        tmp->priority = priority;
        if (front == NULL || priority < front->priority)
        {
            tmp->link = front;
            front = tmp;
        }
        else
        {
            q = front;
            while (q->link != NULL && q->link->priority <= priority)
                q=q->link;
            tmp->link = q->link;
            q->link = tmp;
        }
    }

    void del()
    {
        node *tmp;
        if(front == NULL)
            cout<<"Queue Underflow\n";
        else
        {
            tmp = front;
            cout<<"Deleted item is: "<<tmp->info<<endl;
            front = front->link;
            free(tmp);
        }
    }

    void display()
    {
        node *ptr;
        ptr = front;
        if (front == NULL)
            cout<<"Queue is empty\n";
        else
        {    cout<<"Queue is :\n";
            cout<<"Priority   Item\n";
            while(ptr != NULL)
            {
                cout<<ptr->priority<<"\t\t\t"<<ptr->info<<endl;
                ptr = ptr->link;
            }
        }
    }
};
//class for queue
class Todo : public APP{
    int choice, priority;
    string item;
    Priority_Queue pq;

public:
    void list(){

    do
    {
        cout<<"1.Insert\n";
        cout<<"2.Delete\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Input the item value to be added in the queue : ";
                cin>>item;
                cout<<"Enter its priority : ";
                cin>>priority;
                pq.insert(item, priority);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                break;
            default :
                cout<<"Wrong choice\n";
        }
    }
    while(choice != 4);
    }
};

class Music{
    char name[20],phno[15];
public:
    void getdata();
    void showdata();
    char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
        strcpy(name,nm);
        strcpy(phno,telno);
    }
};

void Music :: getdata(){
    cout<<"\nEnter Music Name : ";
    cin>>name;
    cout<<"Enter Singer name : ";
    cin>>phno;
}

void Music :: showdata(){
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}
//class music

class Mobile{
    Battery b1;

public:

    Mobile(){
        cout<<"Mobile"<<endl;
    }

    void start(){
        int n;string x;

        do{
            cout<<"Enter the option"<<endl;
            cout<<"1.Clock\n2.Settings\n3.Battery\n4.lock\n5.Contacts\n6.Calculator\n7.Message\n8.Todo list\n9.Search Music\n10.Play music"<<endl;
            cin>>n;

            switch(n){
                case 1 : {
                            Clock c1;
                            int op;
                            cout<<"Enter the options"<<endl;
                            cout<<"1.Display time\n2.Display date\n3.Set timer"<<endl;
                            cin>>op;

                            switch(op){

                                case 1: c1.display_time();
                                        break;

                                case 2: c1.display_date();
                                        break;

                                case 3: c1.set_timer();
                                        break;

                            }
                            b1--;
                            break;

                            }

                    case 2: {
                                system("CLS");
                                Settings s1;
                                s1.Selection();
                                b1--;
                                break;
                            }

                    case 3: {
                                Battery b1;
                                b1.show_status();
                                b1--;
                                break;
                            }

                    case 4: {

                                Sleep(3000);
                                cout<<"press Enter key to unlock"<<endl;
                                char c;
                                c=getchar();
                                if(getchar()){
                                    Security s1;
                                    if(s1.getflag() == false)
                                        s1.create();
                                    s1.verify();
                                }
                                break;
                            }

                    case 5: {
                                Contacts c1;
                                c1.list();
                                break;
                            }

                    case 6: {
                                int op = 1;
                                float a, b;
                                Calculator c;

                                do {

                                    cout << endl << "Choice of Operations" << endl;
                                    cout << "1. Add" << endl;
                                    cout << "2. Subtract" << endl;
                                    cout << "3. Divide" << endl;
                                    cout << "4. Multiply" << endl;
                                    cout << "5. Root" << endl;
                                    cout << "6. Exit" << endl;

                                    cin >> op;

                                    if(op < 5){
                                        cout << "Enter the numbers : ";
                                        cin >> a >> b;
                                    }

                                    if(op == 1)
                                        cout << endl <<a<<'+'<<b <<'='<< c.add (a, b) << endl;

                                    else if(op == 2)
                                        cout << endl <<a<<'-'<<b <<'='<< c.subtract (a, b) << endl;

                                    else if(op == 3)
                                        cout << endl <<a<<'/'<<b <<'='<< c.divide (a, b) << endl;

                                    else if(op == 4)
                                        cout << endl <<a<<'*'<<b <<'='<< c.multiply (a, b) << endl;

                                    else if(op == 5){
                                        cout << "Enter the number : ";
                                        cin >> a;
                                        cout << endl <<"sqrt("<<a <<") ="<< c.root (a) << endl;
                                    }

                                        system("CLS");

                                    }while (op != 6);

                                    break;

                            }

                    case 7 : {
                                    Message m1;
                                    m1.text();
                                    break;
                             }

                    case 8 : {
                                    Todo t1;
                                    t1.list();
                                    break;
                             }

                    case 9 : {

                                Music rec;
                                fstream file;
                                file.open("music.txt", ios::ate | ios::in | ios::out | ios::binary);
                                char ch,nm[20];
                                int choice,found=0,choose=1;
                                while(choose){

                                cout<<"\n*****Music Book*****\n";
                                cout<<"1) Add New Record\n";
                                cout<<"2) Display All Records\n";
                                cout<<"3) Search Music No.\n";
                                cout<<"4) Exit\n";
                                cout<<"Choose your choice : ";
                                cin>>choice;
                                switch(choice){
                                case 1 :
                                    rec.getdata();
                                    cin.get(ch);
                                    file.write((char *) &rec, sizeof(rec));
                                    break;

                                case 2 :
                                    file.seekg(0,ios::beg);
                                    cout<<"\n\nRecords in Phone Book\n";
                                    while(file){
                                    file.read((char *) &rec, sizeof(rec));
                                    if(!file.eof())
                                    rec.showdata();
                                }
                                file.clear();
                                break;

                                case 3 :
                                cout<<"\n\nEnter Name : ";
                                cin>>nm;
                                file.seekg(0,ios::beg);
                                found=0;
                                while(file.read((char *) &rec, sizeof(rec)))
                                {
                                if(strcmp(nm,rec.getname())==0)
                                {
                                    found=1;
                                    cout<<"playing \t";
                                    rec.showdata();
                                    }
                                }
                                file.clear();
                                if(found==0)
                                    cout<<"\n\n---Record Not found---\n";
                                break;

                                case 4 : choose=0;
                                }
                        }
                        file.close();


                        }

                    case 10 : {
                                    system("bb.mp3");
                                    break;
                              }

                    default: cout<<"Wrong option"<<endl;

                    }

                    cout<<"Do you want to continue\nyes or no"<<endl;
                    cin>>x;

                    system("CLS");

        }while(x == "yes");
    }
};
//all options are aggregated here


int main(){
    cout<<"Hello world"<<endl;
    Mobile m1;
    m1.start();
    return 0;
}
