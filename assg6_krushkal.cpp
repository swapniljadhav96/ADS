#include<iostream>
#include<string.h>
using namespace std;

class graph
{
    char vertices[10][10];
    int cost[10][10],no;
    public:
    graph();
    void create_graph();
    void display();
    int Position(char[]);
    void Kruskal_algo();
};

graph::graph()
{
    no=0;
    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
      {
        cost[i][j]=999;
      }
}

void graph::create_graph()
{
    char ans,Start[10],end[10];
    int wt,i,j;
    cout<<"\nEnter the number of vertices : ";
    cin>>no;
    cout<<"Entr the name of vertices:-"<<endl;
    for(i=0;i<no;i++)
    {
        cin>>vertices[i];
    }
    do{
        cout<<"\nEnter start and end vertex of the edge :";
        cin>>Start>>end;
        cout<<"\nEnter weight: ";
        cin>>wt;
        i=Position(Start);
        j=Position(end);
        cost[i][j]=cost[j][i]=wt;
        cout<<"\nDo you want to add more edges (Y/N) : ";
        cin>>ans;
    }while(ans=='y' || ans=='Y');
}

void graph::display()
{
    int i,j;
    cout<<"\n\nCost matrix : ";
    for(i=0;i<no;i++)
    {
        cout<<"\n";
        for(j=0;j<no;j++)
        {
            cout<<"\t"<<cost[i][j];
        }
    }
}

int graph::Position(char key[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        if(strcmp(vertices[i],key)==0){
            return i;
        }
    }
    return -1;
}
void graph::Kruskal_algo()
{
    int i,j,v[10]={0},x,y,total_cost=0,min,gr=1,flag=0,temp,d;

    while(flag==0)
    {
        min=999;
        for(i=0;i<no;i++)
        {
            for(j=0;j<no;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        if(v[x]==0 && v[y]==0)
        {
            v[x]=v[y]=gr;
            gr++;
        }
        else if(v[x]!=0 && v[y]==0)
        {
            v[y]=v[x];
        }
        else if(v[x]==0 && v[y]!=0)
        {
            v[x]=v[y];
        }
        else{
            if(v[x]!=v[y])
            {
                d=v[x];
                for(i=0;i<no;i++)
                {
                    if(v[i]==d)
                       v[i]=v[y];
                }
            }
        }
            cout<<"\n";
            cost[x][y]=cost[y][x]=999;
            total_cost=total_cost+min;
            cout<<"\n\t"<<vertices[x]<<"\t\t"<<vertices[y]<<"\t\t"<<min;
            temp=v[0];
            flag=1;
            for(i=0;i<no;i++)
            {
                if(temp!=v[i])
                {
                    flag=0;
                    break;
                }
            }
    }

    cout<<"\nTotal cost of the tree : "<<total_cost;
    }
int main()
{
    graph g;
    g.create_graph();
    g.display();
    g.Kruskal_algo();
    return 0;

}
