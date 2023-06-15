#include<iostream>
#include<string>

using namespace std;

class Graph
{
  int v,e,fuel[10][10],f;
  string city[10];
 
  public:
  void create();
  void display();
}G;



void Graph::create()
{
   cout<<"\nEnter the number of cities : ";
   cin>>v;
   cout<<"\nEnter city name : ";
   for(int i=0;i<v;i++){
       cin>>city[i];
   }
  
   cout<<"\nEnter fuel of edges : ";
   for(int i=0;i<v;i++)
   {
      for(int j=i;j<v;j++){
          if(i==j)
          {
            fuel[i][j]=0;
            continue;
            
          }
          else
          {
             cout<<"\nEnter the fuel of edge "<<city[i]<<" to "<<city[j]<<" : ";
             cin>>f;
             fuel[i][j] = f;
             fuel[j][i] = fuel[i][j];        
         }
     }
   }
}


void Graph::display()
{
    for(int i=0;i<v;i++){
        cout<<"\t"<<city[i];
    }
    cout<<"\n";
    for(int i=0;i<v;i++)
   {
      cout<<city[i];
      for(int j=0;j<v;j++){
             cout<<"\t"<<fuel[i][j];       
        
     }
     cout<<"\n";
   }
}


int main()
{
  G.create();
  G.display();
  return 0;
}





























