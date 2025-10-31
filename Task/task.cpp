#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {  
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
// Move the front node of a linked list in front of another list
    void moveFront(LinkedList& list2) {
        if (list2.head == nullptr) return;  
        Node* temp = list2.head;
        list2.head = list2.head->next;
        temp->next = head;
        head = temp;
    }
// Merge two sorted linked lists 
    Node* mergeSorted(Node* list1, Node* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->data < list2->data) {
            list1->next = mergeSorted(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeSorted(list1, list2->next);
            return list2;
        }
    }
// Remove duplicates from a sorted linked list
    void removeDuplicates() {
        if (!head || !head->next) return;
        
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* dup = current->next;
                current->next = current->next->next;
                delete dup;
            } else {
                current = current->next;
            }
        }
    }
// Move the last node to the front of a linked list 
    void moveLastToFront() {
        if (!head || !head->next) return;
        Node* secondLast = head;
        while (secondLast->next->next)
            secondLast = secondLast->next;
        Node* last = secondLast->next;
        secondLast->next = nullptr;
        last->next = head;
        head = last;
    }
};

int main() {
    LinkedList list1, list2;
    
    
    list1.insertEnd(10);
    list1.insertEnd(20);
    list1.insertEnd(30);

    list2.insertEnd(5);
    list2.insertEnd(15);

    cout << "List1: ";
    list1.display();
    cout << "List2: ";
    list2.display();

    
    list1.moveFront(list2);
    cout << "After move front: ";
    list1.display();
    cout << "List2 after move: ";
    list2.display();

    
    LinkedList list3;
    list3.insertEnd(1);
    list3.insertEnd(2);
    list3.insertEnd(2);  
    list3.insertEnd(3);
    cout << "Before removing duplicates: ";
    list3.display();
    list3.removeDuplicates();
    cout << "After removing duplicates: ";
    list3.display();

    
    list3.moveLastToFront();
    cout << "After moving last to front: ";
    list3.display();

    return 0;
}