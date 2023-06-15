#include<iostream>
#include<string.h>
using namespace std;
int i,key[50],n,c[50];
class hash_table
{
    public:
    int prn,rno;
    string name,add;
    float per;
    void declare();
    void table();
    void accept();
    
}h[50];

void hash_table::declare()
{
    cout<<"\n Enter the number of student records you want to store = ";
    cin>>n;
    cout<<"\n enter the keys : ";
    for(i=0;i<n;i++)
    {
        cin>>key[i];
    }
    for(i=0;i<50;i++)
    {
        h[i].prn=-1;
        c[i]=0;
    }
}

void hash_table::table()

{
    cout<<"\n PRN\tRollnO\tName\tAdd\tPer\tChain";
    for(i=0;i<50;i++)
    {
        cout<<"\n"<<h[i].prn<<"\t"<<h[i].rno<<"\t"<<h[i].name<<"\t"<<h[i].add<<"\t"<<h[i].per<<"\t"<<c[i];
    }

}

void hash_table::accept()
{
    int no,pos;
    for(i=0;i<n;i++)
    {
        no=key[i]%10;
        pos=no;
        do
        {
        if(h[no].prn==-1)
        {
            h[no].prn=key[i];
            cout<<"\n Enter the Rollno, Name, Add, Per";
            cin>>h[no].rno>>h[no].name>>h[no].add>>h[no].per;
            break;
        }
        else
        {
            no++;
            c[pos]=no;
            if(no>50)
            {
                no=0;
            }
        }
        }while(no<50);
        }
        
    }



int main()
{
    hash_table obj;
    obj.declare();
    obj.table();
    obj.accept();
    obj.table();
    return 0;
}
