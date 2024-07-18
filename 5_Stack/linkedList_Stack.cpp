#include <iostream>
using namespace std;
class Node
{
public:
    Node *next = nullptr;
    int data;
};
class Stack
{
    Node *top = new Node;

protected:
    void insertAtLast(int data)
    {
        Node *temp = new Node;
        Node *h;
        temp->data = data;

        if (top == nullptr)
        {
            temp->next = nullptr;
            top = temp;
        }
        else
        {
            h = top;
            while (h->next != nullptr)
            {
                h = h->next;
            }
            h->next = temp;
        }
    }

public:
    Stack();
    void push(int data);
    int peek();
    int pop();
    Stack &operator=(Stack &);
    bool isEmpty();
    ~Stack();
};
Stack::Stack()
{
    this->top = nullptr;
}
bool Stack::isEmpty()
{
    return top == nullptr;
}
void Stack::push(int data)
{
    Node *temp = new Node;
    temp->data = data;
    if (top == nullptr)
    {
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}
int Stack::peek()
{
    if (top == nullptr)
    {
        throw 1;
    }
    else
    {
        return top->data;
    }
}

int Stack::pop()
{
    if (top == nullptr)
    {
        throw 1;
    }
    else
    {
        Node *r = top;
        int datareturn = top->data;
        top = top->next;
        delete r;
        return datareturn;
    }
}
Stack::~Stack()
{
    while (top != nullptr)
    {
        pop();
    }
}

Stack &Stack::operator=(Stack &s)
{

    if (this != &s)
    {
        if (top != nullptr)
        {
            while (top)
            {
                pop();
            }
        }
        Node *temp;
        temp = s.top;
        while (temp)
        {
            insertAtLast(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

void reverseStack(Stack &s)
{
    Stack temp;
    while (!s.isEmpty())
    {
        temp.push(s.pop());
    }
    s = temp;
}

// Check given number is palandrom or not using stack
bool isPalandrome(int number)
{
    int count = 0;
    int num = number;
    bool x = true;
    while (num)
    {
        num = num / 10;
        count++;
    }
    Stack s;
    for (int i = 1; i <= count / 2; i++)
    {
        s.push(number % 10);
        number = number / 10;
    }
    if (count % 2)
    {
        number = number / 10;
    }
   
    while (!s.isEmpty())
    {
        if (number % 10 != s.pop())
        {
            return false;
        }
        number=number/10;
    }
    return true;
}
int main()
{
    // Stack s1;
    // s1.push(4);
    // s1.push(89);
    // s1.push(45);
    // s1.push(43);
    // reverseStack(s1);
    // cout<<s1.peek();
    // cout<<s1.peek();
    // cout<<s1.peek();

    cout << isPalandrome(14222241);
}