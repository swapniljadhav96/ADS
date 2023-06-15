#include <iostream>
#include <limits>
using namespace std;

class bst
{
    int data;
    bst *l, *r;

public:
    void create();
    void insert(bst *root, bst *next);
    void preorder(bst *root);
    int height(bst *root);
   void leafnode(bst *root);
    void mirrorimage(bst *root);
} *root;
int cnt = 0;
void bst::create()
{
    root = new bst;
    bst *next;
    root->l = NULL;
    root->r = NULL;
    cout << "\nenter the data for root";
    cin >> root->data;
    int ch;

    do
    {
        cout << "\ndo you want to insert new node if yes(press 1)/no(press 0)";
        cin >> ch;

        if (ch == 1)
        {
            next = new bst;
            next->l = NULL;
            next->r = NULL;
            cout << "\nenter the data for new node";
            cin >> next->data;

            insert(root, next);
        }
    } while (ch == 1);
}
void bst::insert(bst *root, bst *next)
{
    if (root->data > next->data)
    {
        if (root->l == NULL)
        {
            root->l = next;
        }
        else
        {
            insert(root->l, next);
        }
    }
    else
    {
        if (root->r == NULL)
        {
            root->r = next;
        }
        else
        {
            insert(root->r, next);
        }
    }
}
void bst::preorder(bst *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->l);
        preorder(root->r);
    }
}
int bst::height(bst *root)
{
     int ans = 0;
    int lcnt = 0, rcnt = 0;
    if (root == NULL)
    {
        return ans;
    }
    lcnt = height(root->l);
    rcnt = height(root->r);
    if(l<r) 
    {
        return lcnt+1;
    }
    else
    {
         return rcnt+1;
    }

  
}


void bst::leafnode(bst *root)
{
   //int cnt = 0;
    if (root == NULL)
    {
        return;
    }
        if (root->l == NULL && root->r == NULL)
        {
            cnt=cnt+1;
           
            cout << root->data<<" ";
        }
        
       
            leafnode(root->l);
        
            leafnode(root->r);      
}
void bst::mirrorimage(bst *root)
{
    bst *temp;
    if(root!=NULL)
    {

    temp=root->l;
    root->l=root->r;
    root->r=temp;
    mirrorimage(root->l);
    mirrorimage(root->r);
    }
}
int main()
{
    bst b;
    b.create();
    b.preorder(root);
    cout << "\nheight: " << b.height(root);
    cout<<endl;
    
    b.leafnode(root);
    cout<<"\ntotal no of leafnode :"<< cnt <<endl ;
    cout<<endl;
    b.mirrorimage(root);
    b.preorder(root);

    return 0;
}
