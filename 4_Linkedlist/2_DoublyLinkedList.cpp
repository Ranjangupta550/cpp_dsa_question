
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev = nullptr;
    Node *next = nullptr;
};
class dll
{
private:
    Node *head = new Node();

public:
    dll();
    void insertAtfirst(int);
    void showData();
    void insertAtlast(int data);
    Node *searchNode(int);
    void insertAfter(Node *, int);
    void deletefirst();
    void deleteLast();
    void deleteSpecific(int);

    ~dll();
};

dll::dll()
{
    head = nullptr;
}
void dll::insertAtfirst(int data)
{
    Node *temp = new Node();
    temp->data = data;

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void dll::insertAtlast(int data)
{
    Node *temp = new Node();
    Node *temp2 = new Node();
    temp2 = head;
    temp->data = data;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
    }
}
Node *dll::searchNode(int data)
{
    Node *temp = new Node();
    temp = head;

    // this code return address;

    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }

    return temp;

    // this will return adrees of node and print position of node
    //  if (head==nullptr)
    //  {
    //      cout<<"No element";
    //      return head;
    //  }
    //  else{
    //      while (temp!=nullptr)
    //      {
    //          if (temp->data==data)
    //          {
    //              cout<<node;
    //             return temp;
    //          }
    //          ++node;
    //          temp=temp->next;
    //      }
    //      cout<<"-1";
    //      return temp;
    //  }
}

void dll::showData()
{
    Node *temp = new Node();
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void dll::insertAfter(Node *nodeAfter, int data)
{
    if (nodeAfter)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = nodeAfter->next;
        temp->prev = nodeAfter;
        if (nodeAfter->next != nullptr)
        {
            nodeAfter->next->prev = temp;
        }
        nodeAfter->next = temp;
    }
}
void dll::deletefirst()
{
    Node *temp = head;
    if (head)
    {
        head = head->next;
        if (head)
        {
            head->prev = nullptr;
        }

        delete temp;
    }
    return;
}

dll::~dll()
{
   while (head)
   {
     deletefirst();
   }
   
    
}
int main()
{
    dll d;
    d.insertAtfirst(50);
    d.insertAtfirst(51);
    d.insertAtfirst(55);
    d.insertAtfirst(54);
    d.insertAtlast(90);
    d.insertAtfirst(100);
    // Node* n=d.searchNode(100);
    // d.insertAfter(d.searchNode(100),80);
    // d.insertAfter(n,80);
    d.deleteSpecific(51);

    cout << endl;

    d.showData();
    return 0;
}
