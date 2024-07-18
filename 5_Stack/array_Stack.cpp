#include <iostream>
using namespace std;
class Stack
{
private:
    int *ptr = nullptr;
    int capacity;
    int top;

public:
    Stack(int);
    Stack(Stack &);
    void push(int);
    void peek();
    int pop();
    void reverse();
    bool isEmpty();
    bool isFull();
    int getSize();
    Stack &operator=(Stack &);

    ~Stack();
};
Stack::~Stack()
{
    delete[] ptr;
}
Stack::Stack(int capacity)
{
    if (capacity == 0)
    {
        capacity = 5;
    }
    else if (capacity < 0)
    {
        this->capacity = -capacity;
    }
    ptr = new int[capacity];
    this->capacity = capacity;
    this->top = -1;
}
Stack::Stack(Stack &s)
{
    capacity = s.capacity;
    top = s.top;
    ptr = new int[capacity];
    for (int i = 0; i <= top; i++)
    {
        ptr[i] = s.ptr[i];
    }
}
int Stack::pop()
{
    if (top != -1)
    {
        int temp = ptr[top];
        top -= 1;
        return temp;
    }
    cout << "Empty Stack";
    return top;
}
void Stack::push(int data)
{
    if (top < capacity - 1)
    {
        top = ++top;
        ptr[top] = data;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
    return;
}
void Stack::peek()
{

    if (top == -1)
    {
        cout << "Empty Stack" << endl;
    }
    cout.operator<<(ptr[top]);
}
bool Stack::isEmpty()
{
    return top == -1;
}
bool Stack::isFull()
{
    return top == capacity - 1;
}
void Stack::reverse()
{
    for (int i = 0; i < (top + 1) / 2; i++)
    {
        int temp = ptr[top - i];
        ptr[top - i] = ptr[i];
        ptr[i] = temp;
    }
}
Stack &Stack ::operator=(Stack &s)
{
    capacity = s.capacity;
    top = s.top;
    if (this != &s)
    {

        if (ptr != NULL)
        {
            delete[] ptr;
        }
        ptr = new int[capacity];
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = s.ptr[i];
        }
    }
    return *this;
}
int Stack::getSize()
{
    return top + 1;
}

void reverseStack(Stack &s)
{
    Stack *temp = new Stack(s.getSize());
    while (!s.isEmpty())
    {
        temp->push(s.pop());
    }
    s = *temp;
}

int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.reverse();
    s.peek();

    // cout<<s.underflow();
    // cout<<endl;

    // cout<<s.pop()<<endl;
    // cout << s.peek();
    // s.push(6);
    // cout<<s.peek();

    // s.push(6);
}