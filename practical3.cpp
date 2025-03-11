#include<iostream>
using namespace std;

class graph{
    int v;
    int fuel;
    string city[100];
    int adj[100][100];

    public:
    void accept();
    void display();

}g;

//accept the city names and amount of fuel
void graph ::accept()
{
    cout<<"\nEnter the number of cities:";
    cin>>v;

    cout<<"\nEnter the names of cities:";
    for(int i = 0 ; i < v ;i++)
    {
        cin>>city[i];
    }

    cout <<"\nEnter the amount of fuel required from city 1 to city 2 :";

    for(int i=0; i<v ;i++)
    {
        for(int j =0 ;j <v;j++)
        {
            if(i==j)
            {
                adj[i][j] = 0;
            }
            else{
                cout<<"\nEnter the amount of fuel required from " << city[i] << " to "<<city[j]<<":";
                cin>>adj[i][j];
            }
        }
    }
}

//display the graph
void graph ::display()
{
    cout<<"\n--------------Flight chart-------------\n";
    for(int i = 0 ; i < v ;i++)
    {
        cout<<"\t"<<city[i];
    }
    cout<<endl;
    for(int i=0; i<v ;i++)
    {
        cout<<city[i];
        for(int j =0 ;j <v;j++)
        {
            cout<<"\t"<<adj[i][j];
        }
        cout<<"\n";
    }

}
//main function
int main()
{
    int choice;
    do{
    cout<<"\n1.accept\n2.display";
    cout<<"\nEnter your choice:";
    cin >>choice;

    switch(choice)
    {
        case 1:
        g.accept();
        break;

        case 2:
        g.display();
        break;
    }

}while(choice != 0);
}