#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*prev=nullptr;
    Node*next=nullptr;
};
class Deque
{
private:
   Node*front=new Node;
   Node*rear=new Node;
public:
    Deque();
    void insertAtRear(int);
    void insertAtFront(int);
    int deleteRear();
    int deleteFront();
    int getFront();
    int getRear();

    ~Deque();
};

Deque::Deque(/* args */)
{
    this->front=nullptr;
    this->rear=nullptr;
}
void Deque::insertAtFront(int data){
    Node*temp=new Node;
    temp->data=data;
    if (front!=nullptr)
    {
        temp->next=front;
        front->prev=temp;
        front=temp;
        return;

    }
    else{
        front=rear=temp;
        return;
    }
    

}
void Deque::insertAtRear(int data){
    Node*temp=new Node;
    temp->data=data;
    
    if (rear!=nullptr)
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    else{
        rear=front=temp;
    }
}
int Deque::deleteRear(){
    if(rear==nullptr){
         throw("empty Dqueue");
    }else if(rear==front){
        Node*temp=rear;
        int data=rear->data;
        front=nullptr;
        rear=nullptr;
        delete temp;
        return data;
    }
    else{
        Node *temp=rear;
        int data=rear->data;
        rear=rear->prev;
       delete temp;
        return data;

    }
}
int Deque::deleteFront(){
    if (front==nullptr)
    {
        throw(1);
    }
    else if(front==rear){
        Node*temp=front;
        int data=front->data;
        rear=nullptr;
        front=nullptr;
        delete temp;
        return data;
    }else{
        Node*temp=front;
        int data=front->data;
        front=front->next;
        delete temp;
        return data;
    }
    
}
int Deque ::getFront(){
    if (front!=nullptr)
    {
        return front->data;

    }else{
        throw("empty Dqueue");

    }


    
}
int Deque::getRear(){
    if (rear!=nullptr)
    {
        return rear->data;

    }else{
        throw("empty Dqueue");

    }
}

Deque::~Deque()
{
    while (front!=nullptr)
    {
       deleteFront();
    }
    
}
int main(){
    Deque d1;
    d1.insertAtFront(12);
    cout<<d1.getFront()<<endl;
    cout<<d1.getRear()<<endl;

    return 0;
}