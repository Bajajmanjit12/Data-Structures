/*create binary search tree which accept student information such as name, address,PRN no,CET score marks.
 Based on cet score student will get admission in IIT college ans if student score less than 90% in CET than he will be admitted other than IIT college.
 perform the following operation:
 1. display all student information
 2. Display only IITian student information
 3. Display all non IITian student information
 4. count
 5. height of tree
 6. Mirror image of tree
 7.Search the student information
 8.Modify the student information
 9.Display all ancestors*/

 #include <iostream>
 using namespace std;
 
 class student // creation of class
 {
     int roll_no, score, count = 0;
     string name, prn, add;
     student *LC, *RC;
 
 public:
     void create();
     void insert(student *root, student *next);
     void display(student *root);
     void display_IIT(student *root);
     void display_nonIIT(student *root);
     void display_count();
     int height_of_tree(student *root);
     void search(student *root);
     void update(student *root);
     void display_minmarks(student *root);
     void display_maxmarks(student *root);
     void display_root_node(student *root);
     void display_ancestors(student *root);
     void display_new_entries(student *root);
     void display_last_record(student *root);
    
 
 } *root, *st[100];
 
 //creation of node
 void student ::create()
 {
     int choice;
     student *next;
     root = new student;
     cout << "\nEnter the details of student";
     cout << "\nRollno\tName\tprn_no\taddress\tcet score\n";
     cin >> root->roll_no >> root->name >> root->prn >> root->add >> root->score;
     root->LC = root->RC = NULL;
 
     do
     {
         cout << "\nDo you want to create new record\nIf yes enter '1' and if no enter '0':";
         cin >> choice;
 
         if (choice == 1)
         {
             count++;
             next = new student;
             cout << "\nEnter the details of student";
             cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
             cin >> next->roll_no >> next->name >> next->prn >> next->add >> next->score;
             next->LC = next->RC = NULL;
             insert(root, next);
         }
         
     } while (choice == 1);
 }
 
 //insertion of node in a tree
 void student::insert(student *root, student *next)
 {
     if (root->score > next->score)
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
     else if (root->score < next->score)
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
 }
 
 void student::display(student *root) // display the tree
 {
     int top = -1;
     student *temp;
     temp = root;
     cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
     if (root != NULL) //non recursive inorder traversal
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
                      << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
                 temp = temp->RC;
             }
         } while ((top != -1) || (temp != NULL));
     }
     else
     {
         cout << "\nNo record present";
     }
 }
 
 void student::display_minmarks(student *root) // display the minimum marks
 {
     int top = -1;
     student *temp;
     temp = root;
 
     cout<<"\nThe student who got the least score:\n";
     cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
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
                 if (temp->LC == NULL)
                 {
                     cout << "\n"
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
                     break;
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
 
 void student::display_maxmarks(student *root) // display the maximum marks      
 {
     int top = -1;
     student *temp;
     temp = root;
 
     cout<<"\nThe student who got highest score:\n";
     cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
     if (root != NULL)
     {
         do
         {
             while (temp != NULL)
             {
                 top++;
                 st[top] = temp;
                 temp = temp->RC;
             }
 
             if (top != -1)
             {
                 temp = st[top];
                 top--;
                 if (temp->RC == NULL )
                 {
                     cout << "\n"
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
                     break;
                 }
 
                 temp = temp->LC;
             }
         } while ((top != -1) || (temp != NULL));
     }
     else
     {
         cout << "\nNo record present";
     }
 }
 
 void student::display_IIT(student *root) // display the IITIAN record
 {
     int top = -1;
     student *temp;
     temp = root;
 
     cout<<"\nIITian student record\n";
     cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
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
 
                 if (temp->score >= 90)
                 {
                     cout << "\n"
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
 
 void student::display_nonIIT(student *root) // display the non IITIAN record
 {
     int top = -1;
     student *temp;
     temp = root;
 
     cout<<"Non- IITian student record\n";
     cout << "\nRollno\tName\tprn_no\tadd\tcet score\n";
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
 
                 if (temp->score < 90)
                 {
                     cout << "\n"
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
 
 void student ::display_count() // display total no. of nodes
 {
     if (root == NULL)
     {
         cout << "\nNo records are available\n";
     }
     else
     {
 
         cout << "\nTotal number of students appeared for CET - exam : " << count + 1 << endl;
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
 
 void student::search(student *root) // search the record
 {
     int roll_no, flag = 0;
     cout << "Enter the rollno to search the student:";
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
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
 
 void student::update(student *root) // update the record
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
                          << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
 
                     cout << "\nEnter the new details:";
                     cin >> temp->roll_no >> temp->name >> temp->prn >> temp->add >> temp->score;
                     insert(root,temp);
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
 
 void student ::display_root_node(student *root) // display root nodes
 {
     student *temp;
     temp = root;
 
     cout<<"\nRoot node:\n";
     if (root != NULL)
     {
         cout << "\n" << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
 
     cout<<"\nAncestors:\n";
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
                      << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
                      << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
                      << temp->roll_no << "\t" << temp->name << "\t" << temp->prn << "\t" << temp->add << "\t" << temp->score << "\n";
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
 
 /*void student ::mirror_image(student *root)
 {
     student *temp;
     if(root != NULL)
     {
         mirror_image(root->LC);
         mirror_image(root->RC);
         temp = root->LC;
         root->LC = root->RC;
         root->RC = temp;
     }
     return;
 }*/
 
 int main() //main function 
 {
     student s;
     int choice, result, ans;
 
     do
     {
         cout << "\n\n1.insert record of student\n2.display all student information\n3.display the information of IITIAN student(marks > 90)\n4.display the information of non IITIAN student(marks < 90)\n5.Display the total number of students appered for exams.\n6.display the student having minimum marks\n7.display students having maximum marks.\n8.Search the student\n9.update the student information.\n10.Display the common ancestor\n11.Display all ancestors\n12.Display the last entries [leaf node].\n13.Display all internal nodes\n14.Display the height of tree\n";
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
             s.display_IIT(root);
             break;
 
         case 4:
             s.display_nonIIT(root);
             break;
 
         case 5:
             s.display_count();
             break;
 
         case 6:
             s.display_minmarks(root);
             break;
 
         case 7:
             s.display_maxmarks(root);
             break;
 
         case 8:
             s.search(root);
             break;
 
         case 9:
             s.update(root);
             break;
 
          case 10:
             s.display_root_node(root);
             break;
         
          case 11:
             s.display_ancestors(root);
             break;
 
         case 12:
             s.display_new_entries(root);
             break;
 
         case 13:
             s.display_last_record(root);
             break;
 
         case 14:
             result = s.height_of_tree(root);
             cout << "Height of tree :" << result - 1;
             break;
         }
 
     } while (choice != 0);
 
     return 0;
 }