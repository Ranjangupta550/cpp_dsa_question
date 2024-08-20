#include <iostream>
using namespace std;
class Node
{
public:
    Node *left = nullptr;
    int data;
    Node *right = nullptr;
};
class BST
{
private:
    Node *root;

protected:
    void preRecurssion(Node *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        cout << ptr->data << " ";
        preRecurssion(ptr->left);
        preRecurssion(ptr->right);
    }
    void inorderRecurssion(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        inorderRecurssion(temp->left);
        cout << temp->data << " ";
        inorderRecurssion(temp->right);
    }
    Node *deleteRecc(Node *ptr, int data)
    {
        if (ptr == nullptr)
        {
            return nullptr;
        }
        else if (ptr->data > data)
        {
            ptr->left = deleteRecc(ptr->left, data);
        }
        else if (ptr->data < data)
        {
            ptr->right = deleteRecc(ptr->right, data);
        }
        else
        {
            // NO LEFT AND RIGHT CHILD
            if (ptr->left == nullptr && ptr->right == nullptr)
            {
                delete ptr;
                return nullptr;
            }
            // single child
            if (ptr->left == nullptr || ptr->right == nullptr)
            {
                Node *child = ptr->left ? ptr->left : ptr->right;
                delete ptr;
                return child;
            }
            // both child
            Node *temp1, *temp2;
            temp2 = ptr;
            temp1 = ptr->left;
            while (temp1->right != nullptr)
            {
                temp2 = temp1;
                temp1 = temp1->right;
            }
            ptr->data = temp1->data;
            if (temp2->right == temp1)
            {
                temp2->right = deleteRecc(temp1, temp1->data);
            }
            if (temp2->left == temp1)
            {
                temp2->left = deleteRecc(temp1, temp1->data);
            }
        }
        return ptr;
    }

public:
    BST();
    bool isEmpty();
    void insert(int);
    void preOrder();
    void inorder();
    // void postOrder();
    void deleteData(int);
    Node *search(int);
    ~BST();
};
void BST::preOrder()
{
    if (root != nullptr)
    {
        preRecurssion(root);
    }
}
void BST::inorder()
{
    if (root == nullptr)
    {
        return;
    }
    inorderRecurssion(root);
}

BST::BST()
{
    root = nullptr;
}
bool BST::isEmpty()
{
    if (root == nullptr)
        return true;
    else
        return false;
}
void BST::insert(int data)
{
    if (root == nullptr)
    {
        Node *temp = new Node;
        temp->data = data;
        root = temp;
        return;
    }
    Node *ptr = root;
    while (ptr)
    {
        if (ptr->data == data)
        {
            break;
            return;
        }
        else if (data < ptr->data)
        {
            if (ptr->left == nullptr)
            {
                Node *temp = new Node;
                temp->data = data;
                ptr->left = temp;
                break;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        else
        {
            if (ptr->right == nullptr)
            {
                Node *temp = new Node;
                temp->data = data;
                ptr->right = temp;
                break;
            }
            else
            {
                ptr = ptr->right;
            }
        }
    }
}
void BST::deleteData(int data)
{
    root = deleteRecc(root, data);
}
Node *BST::search(int data)
{
    Node *temp = root;

    while (temp)
    {
        if (temp->data == data)
        {
            return temp;
        }
        else if (temp->data > data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return temp;
}

BST::~BST()
{
    deleteData(root->data);
}
int main()
{
    BST b;
    b.insert(50);
    b.insert(30);
    b.insert(80);
    b.insert(10);
    b.insert(40);
    b.insert(70);
    b.insert(100);
    b.preOrder();
    b.deleteData(67);
    cout << endl;
    b.preOrder();
    cout << endl
         << "inorder" << endl;
    b.inorder();
    // b.inorder();
    cout << endl;
    // b.postOrder();
    Node*temp= b.search(10);
    cout<<temp->data;

    return 0;
}