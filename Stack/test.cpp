#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};
class stack
{
public:
    stack()
    {
        top = nullptr;
    }
    Node *top;
    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull(){
        Node*temp = new Node();
        if(temp == nullptr){
            cout<<"The stack is full, cannot add more item\n";
        }
    }
    void push(int item)
    {
        Node *newnode = new Node();
        newnode->data = item;
        if (isEmpty())
        {
            newnode->next = nullptr;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    int pop()
    {
        Node *delptr = top;
        top = top->next;
        delete delptr;
    }
    int peek()
    {
        return top->data;
    }
    void display()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int count()
    {
        int counter = 0;
        Node *temp = top;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    bool isfound(int item)
    {
        bool found = false;
        Node *temp = top;
        while (temp != nullptr)
        {
            if (temp->data == item)
            {
                found = true;
            }
            temp = temp->next;
        }
        return found;
    }
};
int main()
{
    int item;
    stack s;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Enter item to push\n";
        cin >> item;
        s.push(item);
        s.display();
    }
    cout << s.pop() << "was deleted from stack\n";
    s.display();
    cout << s.pop() << "was deleted from stack\n";
    s.display();
    cout <<"Enter item to search for\n";
    cin >> item;
    if(s.isfound(item)){
        cout<<"item found in the stack\n";
    }
    else{
        cout<<"item not found in the stack\n";
    }
    cout<<"the stack contain : "<<s.count()<<" item(s)\n";
}