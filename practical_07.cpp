/*A medical record system is a software application used to manage medical record including patient information,
medical history and treatment plan ,hash table can be udes as a data structure to efficiently store or retrive medical record.*/

#include<iostream>
using namespace std;

int key[100],n,size;
class Medical_rec{
    int id;
    string name,add;

    public:
    void Table();
    void accept();
    void display();
    void search();
}h[100];

void Medical_rec :: Table()
{
    cout<<"\nEnter the number of keys:";
    cin>>n;

    cout<<"\nEnter the key (Patient Id):";
    for(int i=0;i<n;i++){
        cin >> key[i];
    }
    cout <<"\nEnter size of hash table:";
    cin>> size;

    for(int i=0;i<size;i++)
    {
        h[i].id = -1;

    }
}

void Medical_rec::display()
{
    cout<<"\nLoc\tID\tname\tadd\n";
    for(int i=0;i<size;i++)
    {
        cout<<"\n"<<i<<"\t"<<h[i].id<<"\t"<<h[i].name<<"\t"<<h[i].add;
    }
}

void Medical_rec :: accept()
{
    int loc;
    for(int i=0;i<n;i++)
    {
        loc = key[i]%10;
        int originalLoc = loc;

        while (h[loc].id != -1) 
        {
            loc = (loc + 1) % size;
            if (loc == originalLoc) 
            {
                cout << "\nHash table is full!";
                return;
            }
        }

        h[loc].id = key[i];
        cout << "\nEnter the details of patient:";
        cin >> h[loc].name >> h[loc].add;

}
}

void Medical_rec::search()
{
    int i;
    cout<<"\nEnter the ID to search:";
    cin>>i;
    cout<<"\nLoc\tID\tname\tadd\n";
    for(int i=0;i<size;i++)
    {
        if(i == h[i].id)
        {
        cout<<"\n"<<i<<"\t"<<h[i].id<<"\t"<<h[i].name<<"\t"<<h[i].add;
        break;
        }
        
    }
}
int main()
{
    Medical_rec s;
    int choice;

    do{
    cout<<"\n1.Accept The details\n2.display the hash table\n3.Apply the hash function\n4.Search the record\n";
    cout<<"\nEnter the choice:";
    cin>>choice;

    switch(choice)
    {
        case 1:
        s.Table();
        break;

        case 2:
        s.display();
        break;

        case 3:
        s.accept();
        break;

        case 4:
        s.search();
        break;
    }

    }while(choice != 0);

    return 0;

}