#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *rear=nullptr;
    Node*front=nullptr;
};
class Queue_Linkedlist
{
private:
    Node*head=new Node;

public:
    Queue_Linkedlist();
    void insertAtRear(int data);
    int deleteFront();
    int viewRear();
    int viewFront();
    int countElement();
    ~Queue_Linkedlist();
};

Queue_Linkedlist::Queue_Linkedlist(/* args */)
{
    head=nullptr;
}

Queue_Linkedlist::~Queue_Linkedlist()
{
    while(head!=nullptr){
        deleteFront();
        // cout<<"Ranjan"<<endl;

    }
}
void Queue_Linkedlist::insertAtRear(int data){
    Node*temp=new Node;
    temp->data=data;
    if (head==nullptr)
    {
        head=temp;
        head->front=head;
        head->rear=head;
        return;
    }
    temp->front=head->front;
    head->front=temp;
    head=temp; 
}
int Queue_Linkedlist::viewFront(){
   if (head==nullptr)
   {
        cout<<"empty list ";
        return 0;
   }
   return head->front->data;

}
int Queue_Linkedlist::viewRear(){
    if(head==nullptr){

        cout<<"empty list";
        throw(1);   }
    return head->data;
}
int Queue_Linkedlist::deleteFront(){
    if(head->front==head){
        int data=head->data;
        delete head;
        head=nullptr;
        return data;
    }
    if(head!=nullptr){
        Node *temp=new Node;
        int data;
        temp=head->front;
        data=temp->data;
        head->front=head->front->front;
        delete temp;
        return data;
    }
    else{
        cout<<"Empty Queue"<<endl;
        throw(1);
    }

}
int Queue_Linkedlist::countElement(){
    int count=0;
    if(head==nullptr){
        return count;
    }
    else{
        Node*temp=new Node;
        temp=head->front;
        while (temp!=head)
        {
            ++count;
            temp=temp->front;
        }
        ++count;
        

    }
    return count;
}
int main(){
    Queue_Linkedlist q1;
    q1.insertAtRear(34);
    q1.insertAtRear(34);
    
 
    cout<<q1.viewRear()<<endl;
    cout<<q1.viewFront()<<endl;
    cout<<q1.deleteFront()<<endl;
    cout<<q1.viewFront()<<endl;
    cout<<q1.countElement();
    return 0;
    
}