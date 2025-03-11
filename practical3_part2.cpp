#include<iostream>
using namespace std;

class adj_list{
    int v , fuel;
    string city;
    adj_list *next;
    public:
    void create();
    void add_edges();
    void display();
};

adj_list *head[100];
void adj_list ::create()
{ 
    
    cout << "\nEnter the number of cities:";
    cin >> v;

    cout << "\nEnter the names of city:\n";
    for(int i=0; i<v ;i++)
    {
        head[i] = new adj_list;
        cin >> head[i]->city;
        head[i]->next = NULL;
    }
}

void adj_list :: add_edges()
{
    int e;
    int i,j;
    string source,des;
    adj_list *n1,*temp;
    cout<<"\nEnter the number of edges:";
    cin >> e;

    for( i=0; i<e ;i++)
    {
        cout << "\nEnter the source and destination city:";
        cin >> source >> des;

        for( j =0 ;j<v ;j++)
        {
            if(source == head[j]->city)
            {
                break;
            }
        }

        n1 = new adj_list;
        n1->city = des;

        cout<<"\nEnter the amount of fuel required:";
        cin >>n1->fuel;
        n1->next = NULL;

        temp = head[j];

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }
}

void adj_list:: display()
{
    adj_list *temp;

    for(int i=0;i<v;i++)
    {
        temp = head[i]->next;
        cout <<head[i]->city<<"->";
        while(temp !=NULL)
        {
            cout <<temp->city <<":"<<temp->fuel<<"<->";
            temp = temp->next;
        }
        cout<<" NULL" <<endl;

    }
    
}
int main()
{
    int choice;
    adj_list a;
    do{
    cout <<"\n1.accept the names of cities\n2.display the list\n";
    cout<<"\nEnter your choice:";
    cin>>choice;

    switch(choice)
    {
        case 1: a.create();
        a.add_edges();
        break;

        case 2: 
        a.display();
        break;

        case 0:cout<<"\nExiting..........";break;
    }
    }while(choice != 0);
   return 0; 
}
