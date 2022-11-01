#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class student
{
protected:
    string email,pass,name,roll,dept,l;
public:
    void set_all()
    {
        string a;

        ofstream f1("Student.txt",ios :: app);
        getline(cin,a);
        cout<<"enter email : ";
        getline(cin,email);
        f1<<email<<" \t ";
        cout<<"enter password : ";
        getline(cin,pass);
        f1<<pass<<" \t ";
        cout<<"enter name : ";
        getline(cin,name);
        f1<<name<<" \t ";
        cout<<"enter Roll : ";
        getline(cin,roll);
        f1<<roll<<" \t ";
        cout<<"enter Depertment : ";
        getline(cin,dept);
        f1<<dept<<endl;
        cin.ignore();
        f1.close();
    }
    void show()
    {

        ifstream f1("Student.txt",ios :: in);
        while(getline(f1,l))
        {
            cout<<l<<endl;
        }
        f1.close();
    }
    void view_profile()
    {
        int c=0;
        string s_roll;
        cout<<"Enter roll number : ";
        cin>>s_roll;
        ifstream f1("Student.txt");
        while(f1>>email>>pass>>name>>roll>>dept)
        {
            if(roll == s_roll)
            {
                cout<<" Name = "<<name<<endl;
                cout<<"Roll = "<<roll<<endl;
                cout<<"Department = "<<dept<<endl;
                c++;
            }
        }
        if(c==0)
        {
            cout<<"NO RACORD FOUND"<<endl;
        }
    }
    virtual void set_alldata()
    {

    }
};

class book : public student
{
    string bname,bcode,bwriter,bprice;
    int day,month;
public:
    void set_alldata()
    {
        ofstream f1("book.txt",ios :: app);
        string a;
        getline(cin,a);
        cout<<"enter Book Name : ";
        getline(cin,bname);
        f1<<bname<<" \t ";
        cout<<"enter Book Writer : ";
        getline(cin,bwriter);
        f1<<bwriter<<" \t ";
        cout<<"enter Book Code : ";
        getline(cin,bcode);
        f1<<bcode<<" \t ";
        cout<<"enter Book Price : ";
        getline(cin,bprice);
        f1<<bprice<<endl;
        f1.close();
    }
    void show()
    {
        string l;
        ifstream f1("book.txt",ios :: in);
        while(getline(f1,l))
        {
            cout<<l<<endl;
        }
        f1.close();
    }
    void search_book()
    {
        int c=0;
        string s_name;
        cout<<"Enter search book name : ";
        cin>>s_name;
        ifstream f1("book.txt");
        while(f1>>bname>>bwriter>>bcode>>bprice)
        {
            if(bname == s_name)
            {
                cout<<"Book Name = "<<bname<<endl;
                cout<<"Writer Name = "<<bwriter<<endl;
                cout<<"Book code = "<<bcode<<endl;
                cout<<"Book price = "<<bprice<<endl;
                c++;
            }
        }
        if(c==0)
        {
            cout<<"***************************************"<<endl;
            cout<<"NO RACORD FOUND"<<endl;
        }
    }
};

class enter : public student
{
public:
    void login()
    {
        string l,m,mail,pward;
        int i=0;
        ifstream f1("student.txt");
        cout<<"Enter E-mail : ";
        getline(cin,mail);
        cout<<"Enter pward : ";
        getline(cin,pward);
        while(f1>>email>>pass>>name>>roll>>dept)
        {
            if(email == mail && pass == pward)
            {
                cout<<"WELCOME TO THE PROJECT"<<endl;
                i++;
                break;
            }
        }
        if(i==0)
        {
            cout<<"NO RACORD FOUND"<<endl;
            login();
        }
        f1.close();
    }
    void log_out()
    {
        cout<<"Log Out Successfull"<<endl;
    }
};

class delling
{
    string name,roll,bname;
    int day,month,year;
public:
    book b1;
    void book_racord()
    {
        string r;
        int c=0;
        ifstream f1("racord.txt");
        cout<<"enter your roll : ";
        cin>>r;
        while(f1>>name>>roll>>bname>>day>>month>>year)
        {
            if(roll == r)
            {
                cout<<"Book name = "<<bname<<endl;
                cout<<"Day = "<<day<<endl;
                cout<<"month = "<<month<<endl;
                cout<<"year = "<<year<<endl;
                c++;
            }
        }
        if(c==0)
        {
            cout<<"NO RACORD FOUND"<<endl;
        }
        f1.close();
    }
    void issue()
    {
        string s;
        b1.search_book();
        ofstream f1("racord.txt",ios :: app);
        getline(cin,s);
        cout<<"enter  Name : ";
        getline(cin,name);
        f1<<name<<" \t ";
        cout<<"enter roll  : ";
        getline(cin,roll);
        f1<<roll<<" \t ";
        cout<<"enter Book name : ";
        getline(cin,bname);
        f1<<bname<<" \t ";
        cout<<"enter Booked day : ";
        cin>>day;
        f1<<day<<" \t ";
        cout<<"enter Booked month : ";
        cin>>month;
        f1<<month<<endl;
        cout<<"enter Booked year : ";
        cin>>year;
        f1<<year<<endl;
        f1.close();
    }
    int operator +()
    {
        int d,m,y,i=0,s[2]= {0,0},sum;
        string r;
        ifstream f1("racord.txt");
        cout<<"enter your roll : ";
        cin>>r;
        while(f1>>name>>roll>>bname>>day>>month>>year)
        {
            if(roll == r)
            {
                d=day;
                m=month;
                y=year;
                s[i] = calculation(d,m,y);
                i++;
            }
        }
        sum =(s[0]+s[1]);
        if(i==0)
        {
            cout<<"No Record found"<<endl;
        }

        if(sum<0)
            return 0;
        else
            return (sum);
    }
    int calculation(int d,int m,int y)
    {
        int d1,m1,y1,n1,n2;
        cout<<"Enter this day : ";
        cin>>d1;
        cout<<"Enter this month : ";
        cin>>m1;
        cout<<"Enter this year : ";
        cin>>y1;
        n1 = y*365 + m*30 + d;
        n2 =y1*365 + m1*30 +d1;
        return (n2-n1-30);
    }

};

int info()
{
    cout<<"What are you want now?\n";
    cout<<"1.Log Out\n2.See All Books\n3.See Profile\n4.See Fine\n5.Search Books\n6.See My Books\n7.Open an Account\n8.Issue Book\n9.Modify Book list\n";
    int i;
    cout<<"Press a valid key : ";
    cin>>i;
    return i;
}

int main()
{
    student s1,*bptr;
    bptr = &s1;
    book b1;
    bptr = &b1;
    enter e1;
    delling d1;
    e1.login();
    {

A:
        int a;
        a=info();
        switch(a)
        {
        case 1:
            e1.log_out();
            break;
        case 2:
            b1.show();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 3:
            s1.view_profile();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 4:
            cout<<"Your Fine is = "<<(+d1)*2<<endl;
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 5:
            b1.search_book();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 6:
            d1.book_racord();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 7:
            s1.set_all();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        case 8:
            d1.issue();
            cout<<"***************************************"<<endl;
            goto A;
            break;

        case 9:
            bptr->set_alldata();
            cout<<"***************************************"<<endl;
            goto A;
            break;
        default :
            cout<<"It is not valid";
            goto A;
        }
    }
}
