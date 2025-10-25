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
class queue
{
public:
    Node *front;
    Node *rear;
    queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty()
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int item)
    {
        Node *newnode = new Node();
        newnode->data = item;
        if (isEmpty())
        {
            front = rear = newnode;
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "queue is empty\n";
        }
        else
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                cout << temp->data << "   ";
                temp = temp->next;
            }
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty\n";
        }
        else if (front == rear)
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            Node *delptr = front;
            front = front->next;
            delete delptr;
        }
    }
    int getfront()
    {
        return front->data;
    }

    int getRear()
    {
        return rear->data;
    }
    int count(int counter = 0)
    {

        Node *temp = front;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        cout << endl;
    }
    bool isfound(int item)
    {
        bool found = false;
        Node *temp = front;
        while (temp != nullptr)
        {
            if (temp->data == item)
            {
                found = true;
                temp = temp->next;
            }
        }
        return found;
    }
    void clear()
    {
        while (isEmpty())
        {
            dequeue();
        }
    }
};
int main()
{
    queue q;
    cout << "Enqueue 6 items:\n";
    for (int i = 1; i <= 6; i++)
    {
        int item;
        cout << "Enter item " << i << ": ";
        if (!(cin >> item))
        {
            cerr << "Invalid input\n";
            return 1;
        }
        q.enqueue(item);
    }

    cout << "\nQueue contents: ";
    q.display();

    cout << "\n\nPerforming one dequeue...\n";
    q.dequeue();
    cout << "After one dequeue, queue is:\n";
    q.display();

    cout << "\n\nPerforming second dequeue...\n";
    q.dequeue();
    cout << "After second dequeue, queue is:\n";
    q.display();

    if (!q.isEmpty())
    {
        cout << "\nFront item is : " << q.getfront() << endl;
        cout << "Rear item is  : " << q.getRear() << endl;
    }
    else
    {
        cout << "\nQueue is empty. No front/rear items.\n";
    }

    // Count manually (avoid calling the broken count() implementation)
    int cnt = 0;
    for (Node *t = q.front; t != nullptr; t = t->next)
        ++cnt;
    cout << "The queue contains: " << cnt << " item(s)\n";

    int itemToSearch;
    cout << "Enter item to search in the queue: ";
    cin >> itemToSearch;
    bool found = false;
    for (Node *t = q.front; t != nullptr; t = t->next)
    {
        if (t->data == itemToSearch)
        {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Item found in the queue\n";
    else
        cout << "Item not found in the queue\n";

    cout << "Clearing the queue\n";
    while (!q.isEmpty())
        q.dequeue();
    q.display();

    return 0;
};