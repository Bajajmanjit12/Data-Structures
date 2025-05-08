#include<iostream>
using namespace std;

int n,count =0;

class HeapTree{
    int key[20];
    public:

    void accept();
    void built_max_heap(int key[],int m,int value);
    void insert();
    void display();
    void deletekey();
};

void HeapTree ::accept()
{
    int value;
    cout<<"\nEnter the number of key";
    cin>>n;

    cout<<"\nEnter the key:";
    for(int i=1;i<=n;i++)
    {
        cin>>value;
        built_max_heap(key,i,value);
        count++;
    }
}

void HeapTree::built_max_heap(int key[],int m,int value)
{
    key[m] = value;
    int loc =m;
    while(loc >1)
    {
        int parent = loc/2;
        if(key[parent] < key[loc])
        {
            int temp = key[parent];
            key[parent] = key[loc];
            key[loc] =temp;
            loc = parent;
        }
        else{
            return;
        }
    }
}

void HeapTree ::insert()
{

    if(count > 20)
    {
        cout<<"\nHeap is full";
        return;
    }   
    int nkey;
    cout<<"\nEnter the new key to insert:";
    cin>>nkey;
    count++;
    built_max_heap(key,count,nkey);
}

void HeapTree ::display()
{
    cout<<"\nThe keys in the heap are:";
    for(int i=1;i<=count;i++)
    {
        cout<<key[i]<<"\t";
    }
}

void HeapTree::deletekey() {
    if (count == 0) {
        cout << "Heap is empty. Nothing to delete.\n";
        return;
    }

    cout << "Deleted key: " << key[1] << endl;

    key[1] = key[count]; // Replace root with last element
    count--;             // Reduce size

    // Percolate down
    int loc = 1;
    while (true) {
        int left = 2 * loc;
        int right = 2 * loc + 1;
        int largest = loc;

        if (left <= count && key[left] > key[largest])
            largest = left;
        if (right <= count && key[right] > key[largest])
            largest = right;

        if (largest != loc) {
            swap(key[loc], key[largest]);
            loc = largest;
        } else {
            break;
        }
    }
}

int main()
{
    HeapTree h;
    int choice;

    do{
    cout<<"\n1.Accept the keys\n2.Insert new key\n3.display the record\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        h.accept();
        break;

        case 2:
        h.insert();
        break;

        case 3:
        h.display();
        break;

        case 4:
        h.deletekey();
        break;
    }
}while(choice !=0);

    return 0;
}
