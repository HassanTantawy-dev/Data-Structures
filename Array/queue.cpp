#include <iostream>
using namespace std;

#define size 100
int q[size];
int f = -1, r = -1;
void enqueue(int value);
void dequeue();
void peek();
void display();

int main()
{
    enqueue(10);
    enqueue(3);
    enqueue(4);
    enqueue(15);

    display();

    peek();

    dequeue();
    dequeue();

    display();

    return 0;
}
void enqueue(int value)
{
    if (r != size - 1)
    {
        if (r == -1 && f == -1)
        {
            f++;
            q[++r] = value;
        }
        else
        {
            q[++r] = value;
        }
    }
    else
    {
        cout << "queue is full" << endl;
    }
}

void dequeue()
{
    if (f != -1 && r != -1 && f <= r)
    {
        f++;
    }
    else
    {
        cout << "queue is full" << endl;
    }
}

void peek()
{
    if (f != -1 && r != -1 && f <= r)
    {
        cout << "front element: " << q[f] << endl;
    }
    else
    {
        cout << "queue is empty";
    }
}

void display()
{
    if (f != -1 && r != -1 && f <= r)
    {
        for (int i; i <= r; i++)
        {
            cout << q[i] << endl;
        }
    }
    else
    {
        cout << "queue is empty";
    }
}