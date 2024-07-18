/*
1.Define a class Queue with capacity, front, rear and ptr pointer as member variables.
Implement queue using array.
2.In question 1, define a parameterzied constructor to initialise member variables.
3.In question 1, define a method to insert a new element at the rear in the queue.
4.In question 1, define a method to view rear element of the queue.
5.In question 1, define a method to view front element of the queue.
6.In question 1, define a method to delete the front element of the queue.
7.In question 1, define a destructor to deallocates the memory.
8.In question 1, define a method to check queue overflow
9.In question 1, define a method to check queue underflow.
10.In question 1, Define a method to count number of elements present in the queue
*/

#include <iostream>
using namespace std;
class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int *ptr = nullptr;

public:
    Queue(int capacity);
    void push(int);
    int viewFont();
    int viewRear();
    int deleteFirst();
    bool isUnderflow();
    bool isOverflow();
    int countElement();
    ~Queue();
};

Queue::Queue(int capacity)
{
    this->capacity = capacity;
    this->front = -1;
    this->rear = -1;
    ptr = new int[capacity];
}
void Queue::push(int data)
{
    if (!isOverflow())
    {
        if (isUnderflow())
        {
            rear = front = 0;
            ptr[rear] = data;
        }
        else if (rear == capacity - 1 && front > 0)
        {
            rear = 0;
            ptr[rear] = data;
        }
        else
        {
            rear++;
            ptr[rear] = data;
        }
    }
    else
    {
        cout << "Queue is Overflow ";
    }
}
int Queue::viewFont()
{
    if (front != -1)
    {
        return ptr[front];
    }
    else
    {
        cout << "Empty queue" << endl;
        throw(1);
    }
}
int Queue::viewRear()
{
    if (rear != -1)
    {
        return ptr[rear];
    }
    else
    {
        cout << "Empty Queue" << endl;
        throw(1);
    }
}
int Queue::deleteFirst()
{
    if (!isUnderflow())
    {
        if (front == rear)
        {
            int ret = ptr[front];
            front = -1;
            rear = -1;
            return ret;
        }
        else if (front == capacity - 1)
        {
            int ret = ptr[front];
            front = 0;
            return ret;
        }
        else
        {
            int ret = ptr[front];
            front++;
            return ret;
        }
    }
    else
    {
        cout << "Empty queue" << endl;
        throw(1);
    }
}
bool Queue::isUnderflow()
{
    return rear == -1;
}
bool Queue::isOverflow()
{
    return rear == capacity - 1 && front == 0 || front == rear + 1;
}
int Queue::countElement()
{
    if (!isUnderflow())
    {
        if (front<=rear)
        {
           return rear-front+1;
        }
        else{
            return capacity+rear-front+1;
        }
        
    }
}
Queue::~Queue()
{
    delete[] ptr;
}
int main()
{
    Queue q(5);
    q.push(5);
    q.push(6);
    q.push(7);

    // cout<<q.viewFont()<<endl;//5
    // cout<<q.viewRear()<<endl;//30
    // q.deleteFirst();
    // q.deleteFirst();
    // int c= q.deleteFirst();
    // cout<<c;
    // // cout<<q.deleteFirst();
    cout << q.countElement();
}