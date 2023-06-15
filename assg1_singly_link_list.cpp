#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        node *next;
        int data;
        void create();
        void insert_front();
        void insert_end();
        void insert_any();
        void delete_front();
        void delete_end();
        void delete_any();
        void delete_last();
        void display();

}*start=NULL;
void node :: create()
{
    node *temp;
    temp = new node;
    cout<<"ENter the data:- "<<endl;
    cin>>temp -> data;
    temp -> next = NULL;
    //temp -> next = start;
    start = temp;                
}
void node :: insert_front()
{
    node *temp;
    temp = new node;
    if(start == NULL)
    {
        create();
    }
    else{
        cout<<"Enter the data:- "<<endl;
        cin>>temp-> data;
        
        temp -> next = start;
        start = temp;
    }
}
void node :: insert_end()
{
    node *temp,*temp2,n;
    temp = new node;
    temp2 = new node;
    //temp = new node;
    temp = start;
    cout<<"Enter the data:- "<<endl;
    cin>>temp2 -> data;    
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }       
    temp -> next = temp2;
    temp2 -> next = NULL;  
}
void node :: display()
{
    node *temp;
    temp = start;
    while(temp!= NULL)
    {
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
}
void node :: delete_front()
{
    node *temp;
    temp = start;
    start = start -> next;
    delete temp;
}
void node :: delete_last()
{
    node *temp,*q;
    temp = start;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }  
    
    q = temp ->next;
    temp -> next = NULL;
    delete q;
}
void node :: insert_any()
{
    node *temp,*any;
    temp = new node;
    any = new node;
    int count=0,loc;
    temp = start;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    cout<<"The size of list is:- "<<count<<endl;
    cout<<"Enter the loc where u want to insert:- "<<endl;
    cin>>loc;
    if(loc<count)
    {
        cout<<"Enter the data:- "<<endl;
        cin>>any->data;
        any -> next = NULL;
        temp = start;
        if(temp == NULL)
        {
            cout<<"Cannot Insert ! as list is empty!"<<endl;
            start = any;
        }
        else{
            for(int i=1;i<loc;i++)
            {
                temp = temp -> next;
            }
            any -> next = temp -> next;
            temp -> next = any;
        }
    }
}
void node :: delete_any()
{
    node *temp,*any;
    temp = new node;
    any = new node;
    int count=0,loc;
    temp = start;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    cout<<"The size of list is:- "<<count<<endl;
    cout<<"Enter the loc where u want to insert:- "<<endl;
    cin>>loc;
    if(loc < count)
    {
        temp = start;
        for(int i=1;i<loc;i++)
        {
            temp = temp -> next;
        }
        any = temp -> next;
        temp->next = temp -> next -> next;
        delete any;
    }
}
int main()
{
    node n;
    int ch;
    do{
        cout<<"Menu\n1.Create\n2.Insert at Front\n3.Insert at end\n4.display\n5.delete front\n6.delete last\n7.insert any\n8.delete any\nEnter 0 to exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            n.create();
            break;
            case 2:
            n.insert_front();
            break;
            case 3:
            n.insert_end();
            break;
            case 4:
            n.display();
            break;
            case 5:
            n.delete_front();
            break;
            case 6:
            n.delete_last();
            break;
            case 7:
            n.insert_any();
            break;
            case 8:
            n.delete_any();
            break;
        }
    }while(ch!=0);
    return 0;
}
