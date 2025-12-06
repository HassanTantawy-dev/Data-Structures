#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = nullptr;
    }
    Node *insert(Node *r, int item)
    {
        if (r == nullptr)
        {
            Node *newNode = new Node(item);
            r = newNode;
        }
        else if (item < r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right, item);
        }
        return r;
    }
    void insert(int item)
    {
        root = insert(root, item);
    }

    void preorder(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        cout << r->data << "\t";
        preorder(r->left);
        preorder(r->right);
    }
    void inorder(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }
    void postorder(Node *r)
    {
        if (r == nullptr)
        {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
    }
    Node *search(Node *r, int key)
    {
        if (r == nullptr)
        {
            return nullptr;
        }
        else if (r->data == key)
        {
            return r;
        }
        else if (key < r->data)
        {
            return search(r->left, key);
        }
        else
        {
            return search(r->right, key);
        }
    }
    bool search(int key)
    {
        Node *result = search(root, key);
        if (result == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    Node *findmin(Node *r)
    {
        if (r == nullptr)
        {
            return nullptr;
        }
        else if (r->left == nullptr)
        {
            return r;
        }
        else
        {
            return findmin(r->left);
        }
    }
    Node *findmax(Node *r)
    {
        if (r == nullptr)
        {
            return nullptr;
        }
        else if (r->right == nullptr)
        {
            return r;
        }
        else
        {
            return findmax(r->right);
        }
    }
    Node *Delete(Node *r, int key)
    {
        if (r == nullptr) //Empty tree
        {
            return nullptr;
        }
        if (key < r->data) //item is in left subtree
        {
            r->left = Delete(r->left, key);
        }
        else if (key > r->data) //item is in right subtree
        {
            r->right = Delete(r->right, key);
        }
        else
        {
            if (r->left == nullptr && r->right == nullptr) //leaf node
            {
                r = nullptr;
            }
            else if (r->left != nullptr && r->right == nullptr) //one child on the left
            {
                r->data = r->left->data;
                delete r->left;
                r->left = nullptr;
            }
            else if (r->left == nullptr && r->right != nullptr) //one child on the right
            {
                r->data = r->right->data;
                delete r->right;
                r->right = nullptr;
            }
            else
            {
                Node *max = findmax(r->left); //two children
                r->data = max->data;
                r->left = Delete(r->left, max->data);
            }
        }
        return r;
    }
};

int main()
{
    BST t;
    t.insert(45);
    t.insert(15);
    t.insert(79);
    t.insert(90);
    t.insert(10);
    t.insert(55);
    t.insert(12);
    t.insert(20);
    t.insert(50);
    cout << "display the tree: \n";
    t.preorder(t.root);
    cout << "\n....................................................................\n";
    t.inorder(t.root);
    cout << "\n....................................................................\n";
    t.postorder(t.root);
    cout << "\n....................................................................\n";
    int key;
    cout << "Enter item to search for \n";
    cin >> key;
    if (t.search(key))
    {
        cout << "item found \n";
    }
    else
    {
        cout << "item not found \n";
    }
    cout << "find minmum: \n";
    Node *min = t.findmin(t.root);
    if (min == nullptr)
    {
        cout << "tree is empty \n";
    }
    else
    {
        cout << "minimum item is: " << min->data << "\n";
    }
    cout << "find maximum: \n";
    Node *max = t.findmax(t.root);
    if (max == nullptr)
    {
        cout << "tree is empty \n";
    }
    else
    {
        cout << "maximum item is: " << max->data << "\n";
    }
    cout<<"\nDelete item:\n";
    Node*result=t.Delete(t.root,12);
    cout<<"preorder after delete 12\n";
    t.preorder(result);

    result=t.Delete(t.root,15);
    cout<<"preorder after delete 15\n";
    t.preorder(result);
    
};