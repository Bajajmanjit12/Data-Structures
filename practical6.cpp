/*A student record system is software application used to manage student record including student info ,its 10 and 12 result,
hash table can be udes as a data structure to efficiently store or retrive and student record*/


#include<iostream>
using namespace std;

int key[100],chain[100],n,size;
class student{
    int per,prn;
    string name;

    public:
    void Table();
    void accept();
    void display();
}h[100];

void student :: Table()
{
    cout<<"\nEnter the number of keys:";
    cin>>n;

    cout<<"\nEnter the key (PRN number):";
    for(int i=0;i<n;i++){
        cin >> key[i];
    }
    cout <<"\nEnter size of hash table:";
    cin>> size;

    for(int i=0;i<size;i++)
    {
        h[i].prn = -1;
        chain[i] = -2;
    }
}

void student::display()
{
    cout<<"\nLoc\tPRN\tname\tPer\tchain\n";
    for(int i=0;i<size;i++)
    {
        cout<<"\n"<<i<<"\t"<<h[i].prn<<"\t"<<h[i].name<<"\t"<<h[i].per<<"\t"<<chain[i];
    }
}

void student :: accept()
{
    int loc;
    for(int i=0;i<n;i++)
    {
        loc = key[i]%10;
        int originalLoc = loc;

        while (h[loc].prn != -1) 
        {
            loc = (loc + 1) % size;
            if (loc == originalLoc) 
            {
                cout << "\nHash table is full!";
                return;
            }
        }

        h[loc].prn = key[i];
        cout << "\nEnter the details of student:";
        cin >> h[loc].name >> h[loc].per;

        int hashIndex = key[i] % size;
        if (loc != hashIndex) {
            while (chain[hashIndex] != -2)
                hashIndex = chain[hashIndex];
            chain[hashIndex] = loc;
        }
}
}
int main()
{
    student s;
    int choice;

    do{
    cout<<"\n1.Accept The details\n2.display the hash table\n3.Apply the hash function\n";
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
    }

    }while(choice != 0);

    return 0;

}