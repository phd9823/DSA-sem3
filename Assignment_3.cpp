#include <iostream>
using namespace std;
struct Node
{
int data;
Node *next;
};
class LinkedList
{
private:
Node *start;
public:
LinkedList()
{
start = NULL;
}
void createList()
{
int count, data;
cout << "Enter number of nodes: ";
cin >> count;
if (count <= 0)
{
cout << "Invalid number of nodes.\n";
return;
}
for (int i = 1; i <= count; i++)
{
cout << "Enter value " << i << ": ";
cin >> data;
insertEnd(data);
}
cout << "Linked List Created Successfully.\n";
}
void insertEnd(int data)
{
Node *newNode = new Node;
newNode->data = data;
newNode->next = NULL;
if (start == NULL)
{
start = newNode;
return;
}
Node *current = start;
while (current->next != NULL)
{
current = current->next;
}
current->next = newNode;
}
void display()
{
if (start == NULL)
{
cout << "Linked List is Empty.\n";
return;
}
Node *current = start;
cout << "Linked List: ";
while (current != NULL)
{
cout << current->data << " -> ";
current = current->next;
}
cout << "NULL\n";
}
void deleteNode(int data)
{
if (start == NULL)
{
cout << "Linked List is Empty.\n";
return;
}
Node *current = start;
Node *prev = NULL;
if (start->data == data)
{
start = start->next;
delete current;
cout << "Node Deleted.\n";
return;
}
while (current != NULL && current->data != data)
{
prev = current;
current = current->next;
}
if (current == NULL)
{
cout << "Value not found.\n";
return;
}
prev->next = current->next;
delete current;
cout << "Node Deleted.\n";
}
};
int main()
{
LinkedList list;
int choice, data;
do
{
cout << "\n========== MENU ==========\n";
cout << "1. Create Linked List\n";
cout << "2. Insert at End\n";
cout << "3. Delete Node\n";
cout << "4. Display Linked List\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
switch (choice)
{
case 1:
list.createList();
break;
case 2:
cout << "Enter value to insert: ";
cin >> data;
list.insertEnd(data);
break;
case 3:
cout << "Enter value to delete: ";
cin >> data;
list.deleteNode(data);
break;
case 4:
list.display();
break;
case 5:
cout << "Exiting...\n";
break;
default:
cout << "Invalid Choice!\n";
}

} while (choice != 5);
return 0;
}
