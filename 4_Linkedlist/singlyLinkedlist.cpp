#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next = NULL;
};
class SinglyLinkedList
{
private:
    Node *head;

public:
    int position = 0;
    SinglyLinkedList();
    void insertAtFirst(int);
    void showlinkedlist();
    void insertAtLast(int);
    Node *search(int);
    void insertatNode(int, int);
    void deleteAtFirst();
    void deleteAtLast();
    ~SinglyLinkedList();
};
SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
}
void SinglyLinkedList::insertAtFirst(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
    position++;
}
void SinglyLinkedList::insertAtLast(int data)
{
    position++;

    Node *temp;
    Node *temp2 = new Node;
    temp2->data = data;
    temp2->next = NULL;

    if (head == NULL)
    {
        head = temp2;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = temp2;
    }
}
void SinglyLinkedList::insertatNode(int atnode, int val)
{
    if (atnode>position||atnode<0)
    {
        cout<<endl<<"invalid input "<<endl;
    }
    else if (atnode==0)
    {
       insertAtFirst(val);
    }
    else{
        Node *temp;
        temp=head;
        Node*temp2=new Node;
        temp2->data=val;
        for (int i = 1; i < atnode; i++)
        {
            temp=temp->next;
          
        }
        temp2->next=temp->next;
        temp->next=temp2;
        position++;
    }

    
    
}
Node *SinglyLinkedList::search(int val)
{

    Node *temp;
    temp = head;

    while (temp != NULL)
    {

        if (temp->data == val)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}
void SinglyLinkedList::deleteAtFirst()
{
    Node *temp;
    position--;
    if (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void SinglyLinkedList::deleteAtLast()
{
    position--;
    if (head != NULL)
    {

        Node *temp;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *temp2;
        temp2 = temp->next;
        temp->next = NULL;
        delete temp2;
    }
}
void SinglyLinkedList::showlinkedlist()
{
    Node *temp;
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

SinglyLinkedList::~SinglyLinkedList()
{
    while (head)
    {
        deleteAtFirst();
        position--;
    }
    delete head;
}
int main()
{
    SinglyLinkedList s1;
    s1.insertAtFirst(1);
    s1.insertAtFirst(2);
    s1.insertAtFirst(3);
    s1.insertAtFirst(4);
    s1.insertAtFirst(5);
    s1.insertatNode(2,6);
    s1.insertatNode(6,12);
    // s1.insertatNode(7,50);
    // cout<<s1.position;
    cout << s1.position;
    cout<<endl;
    // s1.deleteAtLast();
    s1.showlinkedlist();
    cout << endl;

    // s1.insertAtFirst(90);
    // s1.insertAtLast(50);
    // s1.showlinkedlist();
    return 0;
}
