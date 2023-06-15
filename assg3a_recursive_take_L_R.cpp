#include<iostream>
using namespace std;

class bt
{
public:
    string data;
    bt *lchild,*rchild;
    void create();
    void insert(bt *root,bt *next);
    void inorder(bt *root);
    void preorder(bt *root);
    void postorder(bt *root);
}*root;


void bt::create()
{
 bt *next;
 int ch; 
 root=new bt;
 root->lchild=NULL;
 root->rchild=NULL;
 
 cout<<"\nEnter the data for root node:- ";
 cin>>root->data;

 do
 {
   cout<<"\nDo you want to continue? (enter 1 if yes):";
   cin>>ch;
if(ch == 1)
 {
  next=new bt;
  next->lchild=NULL;
  next->rchild=NULL;
 
 cout<<"\nenter new node data:";
 cin>>next->data;
 insert(root,next);
 }
  }while(ch==1);
 }
void bt::insert(bt *root,bt *next)
{
char chr;
 cout<<"\nThe Data for root:: "<<root->data<<"\nWhere you want to enter at left or right? (L/R):: ";
 cin>>chr;
 if(chr=='l'||chr=='L')
 {
  if(root->lchild==NULL)
  {
    root->lchild=next;
   }
  else
   {
    insert(root->lchild,next);
   } 
 
 }
 else
 {
  if(root->rchild==NULL)
  {
     root->rchild=next;
   }
   else
   {
     insert(root->rchild,next);
   }
 
 }
 }
void bt::inorder(bt *root)
{

if(root!=NULL)
{
  inorder(root->lchild);
  cout<<root->data<<"\t";
  inorder(root->rchild);

}
}
void bt::preorder(bt *root)
{

if(root!=NULL)
{
  cout<<root->data<<"\t";
  inorder(root->lchild);
  inorder(root->rchild);

}
}
void bt::postorder(bt *root)
{

if(root!=NULL)
{
inorder(root->lchild);
inorder(root->rchild);
cout<<root->data<<"\t";

}
}
int main()
{
bt b;
 int n,ch; //next=new bt;
do{ 
 cout<<"\nmenu";
 cout<<"\n1.create";
 cout<<"\n2.inorder";
 cout<<"\n3.preorder";
 cout<<"\n4.postorder";
 cout<<"\n5.exit";
 cout<<"\nenter choice:";
 cin>>ch;
switch(ch)
{
 case 1:
      b.create();
      break;
 case 2:
      b.inorder(root);
      break;
 case 3:
      b.preorder(root);
      break;
 case 4:
      b.postorder(root);
      break;
}
}while(ch!=5);
}
