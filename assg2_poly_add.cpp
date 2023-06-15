#include<iostream>
using namespace std;
class node
{
    public:
        int co,ex;
        node *next,*prev;
        void accept();
        void display();
}*h1=NULL,*h2=NULL,*h3=NULL,*e1=NULL,*e2=NULL,*e3=NULL;


void node :: accept()
{
    node *p1,*p2;
    int deg1,deg2;
    cout<<"Enter the degree of 1st polynomial:- "<<endl;
    cin>>deg1;
    for(int i=deg1;i>=0;i--)
    {
        p1 = new node;
        p1 -> next = NULL;
        p1 -> prev = NULL;
        cout<<"Enter the coefficient of degree "<<i<<" :-"<<endl;
        cin>>p1->co;
        p1->ex = i;
        if(h1 == NULL)
        {
            h1 = p1;
            e1 = p1;
        }
        else{
            p1->prev = e1;
            e1 -> next = p1;
            e1 = p1;
        }
    }
    cout<<"Enter the degree of 2nd polynomial:- "<<endl;
    cin>>deg2;
    for(int j=deg2;j>=0;j--)
    {
        p2 = new node;
        p2 -> next = NULL;
        p2 -> prev = NULL;
        cout<<"Enter the coefficient of degree "<<j<<" :-"<<endl;
        cin>>p2->co;
        p2->ex = j;
        if(h2 == NULL)
        {
            h2 = p2;
            e2 = p2;
        }
        else{
            p2->prev = e2;
            e2 -> next = p2;
            e2 = p2;
        }
    }

}
void node :: display()
{
    node *temp1,*temp2,*temp3;
    temp1 = h1;
    temp2 = h2;
    cout<<"The first polynomial is:- "<<endl;
    while (temp1 != NULL)
    {
        if(temp1->ex>0)
        {
            cout<<temp1->co<<"X^"<<temp1->ex<<" + ";
        }
        else{
            cout<<temp1->co<<"X^"<<temp1->ex<<" =0"<<endl;
        }
        temp1 = temp1 -> next;
    }
    cout<<"The second polynomial is:- "<<endl;
    while (temp2 != NULL)
    {
        if(temp2->ex>0)
        {
            cout<<temp2->co<<"X^"<<temp2->ex<<" + ";
        }
        else{
            cout<<temp2->co<<"X^"<<temp2->ex<<" =0"<<endl;
        }
        temp2 = temp2 -> next;
    }
    temp1 = h1;
    temp2 = h2;
    while(temp1 != NULL && temp2 != NULL)
    {
        node *p3;
        p3 = new node;
        p3 -> next = NULL;
        p3 -> prev = NULL;
        if(temp1 -> ex == temp2 ->ex)
        {
            p3 -> co  = temp1 -> co + temp2 -> co;
            p3 -> ex = temp1 -> ex;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else if(temp1 -> ex > temp2 -> ex)
        {
            p3 -> co = temp1 -> co;
            p3 -> ex = temp1 -> ex;
            temp1 = temp1 -> next;
        }
        else if(temp2 -> ex > temp1 -> ex)
        {
            p3 -> co = temp2 -> co;
            p3 -> ex = temp2 -> ex;
            temp2 = temp2 -> next;
        }
        if(h3 == NULL)
        {
            h3 = p3;
            e3 = p3;
        }
        else{
            e3 -> next = p3;
            p3 -> prev = e3;
            e3 = p3;
        }
    }
    cout<<"The resultant polynomial after addition is:- "<<endl;
    temp3 = h3;
    while (temp3 != NULL)
    {
        if(temp3->ex>0)
        {
            cout<<temp3->co<<"X^"<<temp3->ex<<" + ";
        }
        else{
            cout<<temp3->co<<"X^"<<temp3->ex<<" =0"<<endl;
        }
        temp3 = temp3 -> next;
    }
}
int main()
{
    node a;
    a.accept();
    a.display();
    return 0;
}
