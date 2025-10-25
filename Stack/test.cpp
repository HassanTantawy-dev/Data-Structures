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
    bool isfull()
    {
        Node *temp = new Node();
        if (temp == nullptr)
        {
            cout << "The stack is full, cannot add more item\n";
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
    cout << "Stack Implementation\n";

    for (int i = 1; i <= 3; ++i)
    {
        cout << "\nEnter item #" << i << " to push: ";
        if (!(cin >> item)) 
        {
            cout << "Invalid input. Exiting...\n";
            return 0;
        }
        s.push(item);
        cout << "Stack contains: ";
        s.display();
    }

    cout << "\nPerforming pop operations:\n";
    for (int i = 1; i <= 2; ++i)
    {
        if (!s.isEmpty())
        {
            cout << s.peek() << " was popped from stack\n";
            s.pop();
            cout << "Stack contains: ";
            s.display();
        }
        else
        {
            cout << "Stack is empty, cannot pop\n";
        }
    }

    cout << "\nEnter item to search for: ";
    if (!(cin >> item))
    {
        cout << "Invalid input. Exiting...\n";
        return 0;
    }
    cout << (s.isfound(item) ? "Item found in the stack\n" : "Item not found in the stack\n");

    cout << "\nThe stack contains " << s.count() << " item(s)\n";
    return 0;
}