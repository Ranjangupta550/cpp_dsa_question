#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
};
class CDDL
{
private:
    Node *head;

public:
    CDDL();
    void insertAtFirst(int);
    void insertAtLast(int);
    Node *seardchNode(int);
    void afterNode(Node *, int);
    void deleteFirst();
    void deleteLast();
    void deletSpecificNode(Node*);
     ~CDDL();
    void showData();
};
CDDL::CDDL()
{
    head = nullptr;
}
void CDDL::insertAtFirst(int data)
{
    Node *temp = new Node;
    temp->data = data;
    if (head == nullptr)
    {
        head = temp;
        head->next = head;
        head->prev = head;
        return;
    }
    else
    {
        temp->next = head;
        head->prev->next = temp;
        temp->prev = head->prev;
         head->prev = temp;
        head=temp;
    }
}
void CDDL::deleteFirst()
{
    if (head == nullptr || (head->next == head && head->prev == head))
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node *temp = head;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        delete temp;
    }
}
void CDDL::deleteLast(){
    if (head==nullptr || ( head->next==head && head->prev==head))
    {
        delete head;
        head=nullptr;
    }
    else{
        Node*temp=head->prev;
        head->prev->prev->next=head;
        head->prev=head->prev->prev;
        delete temp;


    }
    
}

void CDDL::showData()
{
    if (head == nullptr)
    {
        cout << "Empty CDDL";
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}
void CDDL::insertAtLast(int data)
{
    Node *temp = head;
    Node *temp2 = new Node;
    temp2->data = data;

    if (head == nullptr)
    {
               head=temp2;
        head->next = head;
        head->prev = head;

        return;
    }
    else
    {
        while (temp->next != head)
        {

            temp = temp->next;
        }

        temp2->next = temp->next;
        temp->next = temp2;
        head->prev = temp2;
        temp2->prev = temp;
    }
}
Node *CDDL::seardchNode(int data)
{
    Node *temp = head;

    if (head == nullptr)
    {
        return NULL;
    }

    do
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;

    } while (temp != head);

    return NULL;
}
void CDDL::afterNode(Node *aftNode, int data)
{

    if (head == nullptr || aftNode == nullptr)
    {
        cout << "invalid";
        return;
    }
    Node *temp2 = new Node;
    temp2->data = data;
    if (aftNode->next == head)
    {
        insertAtLast(data);
        return;
    }
    Node *temp = head;
    do
    {
        if (temp == aftNode)
        {
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (temp != aftNode)
    {
        cout << "address not found";
        delete temp2;
        return;
    }

    temp2->next = temp->next;
    temp->next->prev = temp2;
    temp2->prev = temp;
    temp->next = temp2;
}
void CDDL::deletSpecificNode(Node* delNode){
        if (head==nullptr||delNode==nullptr)
        {
            cout<<"invalid node";
            return;
        }
        else if(delNode==head){
            deleteFirst();
            return;
        }
        else if(delNode->next==head){
            deleteLast();
            return;
        }
        else{
            delNode->prev->next=delNode->next;
            delNode->next->prev=delNode->prev;
            delete delNode;
            return;
        }
        cout<<"invalid address";
}
CDDL::~CDDL(){
    while(head!=nullptr){
          deleteFirst();
   
    }
  
}


int main()
{
    CDDL cd;
    cd.insertAtFirst(12);
    cd.insertAtLast(67);
    cd.insertAtFirst(15);
    cd.insertAtLast(37);
    cd.insertAtFirst(18);
    cd.insertAtLast(97);

  
    Node*temp=cd.seardchNode(37);
    cd.deletSpecificNode(temp);
        cd.showData();
}
