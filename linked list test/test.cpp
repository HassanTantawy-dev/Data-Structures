#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val = 0) : data(val), next(nullptr) {}
};

class linkedlist
{
public:
    Node *head;
    linkedlist()
    {
        head = nullptr;
    }
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertFirst(int newvalue)
    {
        Node *newnode = new Node(newvalue);
        if (head == nullptr)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "   ";
            temp = temp->next;
        }
    }
    int count()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool isfound(int key)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
int main()
{
    linkedlist lst;
    if (lst.isEmpty())
    {
        cout << "list is empty" << endl;
    }
    else
    {
        cout << "the list contain :" << lst.count() << endl;
    }
    int item;
    cout << "\nEnter item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\nEnter item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\nEnter item to insert in the list: ";
    cin >> item;
    lst.insertFirst(item);
    lst.display();
    cout << "\nthe list contain : " << lst.count() << endl;
    cout << "Enter item to search in the list: ";
    cin >> item;
    if (lst.isfound(item))
    {
        cout << "item found in the list\n";
    }
    else
    {
        cout << "item not found in the list\n";
    }
}
