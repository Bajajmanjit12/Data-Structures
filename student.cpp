#include <iostream>
using namespace std;

class student // creation of class
{
    int roll_no, count = 0;
    string name, prn;
    student *LC, *RC, *next;

public:
    void create();
    void insert(student *root, student *next);
    void display(student *root);
    void display_new_entries(student *root);
    void display_last_record(student *root);
    void display_root_node(student *root);
    void display_ancestors(student *root);
    void display_count();
    int height_of_tree(student *root);
    void search(student *root);
    void update(student *root);
    //int height_of_node(student *root);

} *root, *st[100];

void student ::create() // create the node
{

    int choice;
    root = new student;
    cout << "\nEnter the details of student who register:";
    cin >> root->roll_no >> root->name >> root->prn;
    root->LC = root->RC = NULL;

    do
    {
        cout << "\nDo you want to create newnode:";
        cin >> choice;

        if (choice == 1)
        {
            count++;
            next = new student;
            cout << "\nEnter the details of student who register:";
            cin >> next->roll_no >> next->name >> next->prn;
            next->LC = next->RC = NULL;
            insert(root, next);
        }
    } while (choice == 1);
}

void student ::insert(student *root, student *next) // insert the node
{
    char chr;
    cout << "\nwhere do you want to insert from(l/r) " << root->roll_no << ":";
    cin >> chr;

    if (chr == 'l' || chr == 'L')
    {
        if (root->LC == NULL)
        {
            root->LC = next;
        }
        else
        {
            insert(root->LC, next);
        }
    }
    else if (chr == 'r' || chr == 'R')
    {
        if (root->RC == NULL)
        {
            root->RC = next;
        }
        else
        {
            insert(root->RC, next);
        }
    }
    else
    {
        cout << "\nInvalid choice!!";
    }
}
void student::display(student *root) // display the tree
{
    int top = -1;
    student *temp;
    temp = root;
    cout<<"\nrollno\tname\tprn_no\n";
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                cout << "\n"
                     << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";
                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }
}

void student::display_new_entries(student *root) // display new entries
{
    int top = -1;
    student *temp;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;

                if (temp->LC == NULL && temp->RC == NULL)
                {
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";
                }

                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }
}

void student::display_last_record(student *root) // display internal nodes
{
    int top = -1;
    student *temp;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;

                if ((temp->LC != NULL || temp->RC != NULL) && temp != root)
                {
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";
                }

                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }
}

void student::display_ancestors(student *root) // display internal and root nodes
{
    int top = -1;
    student *temp;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;

                if ((temp->LC != NULL || temp->RC != NULL))
                {
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";
                }

                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }
}

void student ::display_root_node(student *root) // display root nodes
{
    if (root != NULL)
    {
        cout << "\n"
             << root->roll_no << "\t" << root->name << "\t" << root->prn << "\n";
    }
    else
    {
        cout << "\nNo record present";
    }
}

void student ::display_count() // display total no. of nodes
{
    if (root == NULL)
    {
        cout << "No records are available";
    }
    else
    {

        cout << "Total number of nodes:" << count + 1;
    }
}

int student ::height_of_tree(student *root) // display the height of tree
{
    int lht, rht, fht;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        lht = height_of_tree(root->LC);
        rht = height_of_tree(root->RC);

        if (lht > rht)
        {
            fht = lht + 1;
        }
        else
        {
            fht = rht + 1;
        }
    }

    return fht;
}

void student::search(student *root) // search record
{
    int roll_no, flag = 0;
    cout << "Enter the rollno to search :";
    cin >> roll_no;

    int top = -1;
    student *temp;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                if (temp->roll_no == roll_no)
                {
                    flag = 1;
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";
                }
                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }

    if (flag == 0)
    {
        cout << "\nNo student available";
    }
}

void student::update(student *root) // update record
{
    int roll_no, flag = 0;
    cout << "Enter the rollno to update the student's information :";
    cin >> roll_no;

    int top = -1;
    student *temp;
    temp = root;
    if (root != NULL)
    {
        do
        {
            while (temp != NULL)
            {
                top++;
                st[top] = temp;
                temp = temp->LC;
            }

            if (top != -1)
            {
                temp = st[top];
                top--;
                if (temp->roll_no == roll_no)
                {
                    flag = 1;
                    cout << "\n"
                         << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\n";

                    cout << "\nEnter the new details:";
                    cin >> temp->roll_no >> temp->name >> temp->prn;
                }
                temp = temp->RC;
            }
        } while ((top != -1) || (temp != NULL));
    }
    else
    {
        cout << "\nNo record present";
    }

    if (flag == 0)
    {
        cout << "\nNo student available";
    }
}

/*int student ::height_of_node(student *root) // display the height of node
{
    int rno;
    cout<<"Enter the roll no:(height till that node)";
    cin>>rno;
    int lht, rht, fht;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        
        lht = height_of_node(root->LC);
        rht = height_of_node(root->RC);

        if (lht > rht)
        {
            fht = lht + 1;
        }
        else
        {
            fht = rht + 1;
        }
        }
    
    return fht;
}*/
// MAIN FUNCTION
int main()
{
    student s;
    int choice,result,ans;

    do
    {
        cout << "\n\n1.insert\n2.display\n3.Display the new entries\n4.Display last record(internal nodes)\n5.Display the common ancestors\n6.Display all ancestors\n7.Total Number of records\n8.Search the student record\n9.Update the information of student\n10.Height of tree\n11.height of node\n";
        cout << "\nEnter your choice:";

        cin >> choice;

        switch (choice)
        {
        case 1:
            s.create();
            break;

        case 2:
            s.display(root);
            break;

        case 3:
            s.display_new_entries(root);
            break;

        case 4:
            s.display_last_record(root);
            break;

        case 5:
            s.display_root_node(root);
            break;

        case 6:
            s.display_ancestors(root);
            break;

        case 7:
            s.display_count();
            break;

        case 8:
            s.search(root);
            break;

        case 9:
            s.update(root);
            break;

        case 10:
             result = s.height_of_tree(root);
            cout << "Height of tree :" << result - 1;
            break;

        /*case 11:
            ans = s.height_of_node(root);
            cout << "Height of node till that roll no :" << ans - 1;*/
        }

    } while (choice != 0);

    return 0;
}