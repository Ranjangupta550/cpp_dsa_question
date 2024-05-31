#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
};
class CLL
{
    Node *last = nullptr;

public:
    CLL();
    void insertAtFirst(int data);
    void insertAtLast(int data);
    void showData();
    Node *searchNode(int data);
    void insertAfter(Node *prevNode, int data);
    void deleteFirst();
    void deleteLast();
    void deleteSpecific(int data);
    ~CLL();
};
CLL::CLL()
{
    last = nullptr;
}
void CLL::insertAtLast(int data)
{
    Node *temp = new Node();
    temp->data = data;
    if (last == nullptr)
    {
        last = temp;
        last->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void CLL::insertAtFirst(int data)
{
    Node *temp = new Node;
    temp->data = data;

    if (last == nullptr)
    {
        last = temp;
        last->next = temp;
    }
    else
    {

        temp->next = last->next;
        last->next = temp;
    }
}
Node *CLL::searchNode(int data)
{

    if (last == nullptr)
    {
        return nullptr;
    }

    Node *temp = last;
    do
    {

        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != last);
    return nullptr;
}
void CLL::insertAfter(Node *prevNode, int data)
{
    if (prevNode == nullptr)
    {
        cout << "previwes node not found";
        return;
    }
    else
    {
        if (prevNode == last)
        {
            insertAtLast(data);
        }

        Node *temp = new Node;
        temp->data = data;
        temp->next = prevNode->next;
        prevNode->next = temp;
    }
    return;
}
void CLL::deleteFirst()
{

    if (last == nullptr)
    {
        cout << "empty list";
        return;
    }
    Node *temp = last->next;
    if (last->next == last)
    {
        delete last;
        last = nullptr;
        return;
    }
    else
    {
        last->next = temp->next;
        delete temp;
        temp = nullptr;
        return;
    }
}
void CLL::deleteLast()
{
    Node *temp = last;
    if (last == nullptr)
    {
        cout << "empty list";
        return;
    }
    else if (temp->next == last)
    {
        delete last;
        last = nullptr;
        return;
    }
    else
    {

        do
        {
            temp = temp->next;
        } while (temp->next != last);
        temp->next = last->next;
        delete last;
        last = temp;
        return;
    }
}
void CLL::deleteSpecific(int data)
{
    if (last == nullptr)
    {
        cout << "empty list";
        return;
    }
    else
    {
        Node *temp = last;
       
        if (last->data == data)
        {
            deleteLast();
            return;
        }
        else
        {
            do
            {
                if (temp->next->data == data)
                {   

                    Node *temp2 = temp->next;
                    temp->next = temp->next->next;
                    delete temp2;
                    temp2 = nullptr;
                    return;
                }
                temp=temp->next;

            } while (temp != last);
            return;
        }
    }
}
CLL::~CLL()
{
  if (last != nullptr)
  {
    Node*temp=last->next;
    while (temp!=last)
    {
       Node*temp2=temp->next;
         delete temp;
        temp=temp2;
    }
  }
  delete last;
}
  
void CLL::showData()
{
    if (last == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }
    Node *temp = last;
    temp = last->next;
    cout << temp->data << " ";
    temp = temp->next;
    while (temp != last->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int main()
{
    CLL list;

    list.insertAtLast(20);
    list.insertAtLast(30);
    list.deleteSpecific(30);
    list.showData();
    return 0;
}