
#include <iostream>
using namespace std;
class Array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    Array(int);
    Array(Array &);
    Array &operator=(Array &a);
    bool isEmpty();
    void append(int);
    void showArray();
    void atSpecificIndex(int, int);
    void editAt(int, int);
    void deleteIndexAt(int);
    bool isFull();
    int getElement(int);
    int countElement();
    int findElement(int);

    ~Array();
};

Array::Array(int size)
{
    if (size > 0)
    {
        this->capacity = size;
        this->lastindex = -1;
        ptr = new int[capacity];
        cout << "Array is created of size " << size << endl;
    }
    else
    {
        cout << "Invalid Size" << endl;
    }
}
Array::Array(Array &a)
{
    capacity = a.capacity;
    lastindex = a.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = a.ptr[i];
    }
}
Array &Array::operator=(Array &a)
{
    if (this != &a)
    {
        if (ptr != NULL)
        {
            delete[] ptr;
        }

        capacity = a.capacity;
        lastindex = a.lastindex;
        ptr = new int[capacity];
        for (int i = 0; i <= lastindex; i++)
        {
            ptr[i] = a.ptr[i];
        }
    }
    return *this;
}
bool Array::isEmpty()
{
    return (lastindex == -1);
}
void Array::append(int data)
{
    if (lastindex < capacity - 1)
    {
        ++lastindex;
        ptr[lastindex] = data;
        // cout<<endl<<lastindex<<" = "<<ptr[lastindex];
    }
    else
    {
        cout << "Array is out of bound" << endl;
    }
}

void Array::showArray()
{
    for (int i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }
}
void Array::atSpecificIndex(int atindex, int data)
{
    if (atindex < 0 || atindex > lastindex + 1)
    {
        cout << "array out of bound" << endl;
    }
    else if (isFull())
    {
        cout << "array is full" << endl;
    }
    else
    {
        for (int i = lastindex; i >= atindex; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[atindex] = data;
        lastindex++;
    }
}
void Array::editAt(int atindex, int data)
{
    if (atindex > -1 && atindex <= lastindex)
    {
        ptr[atindex] = data;
    }
    cout << "array out of bound " << endl;
}
void Array::deleteIndexAt(int atindex)
{

    if (atindex < 0 || atindex > lastindex)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        for (int i = atindex; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;
    }
}

bool Array::isFull()
{
    cout << endl;
    return (lastindex == capacity - 1);
}
int Array::getElement(int ofindex)
{
    // if (ofindex>-1&&lastindex>=ofindex)
    // {
    //     cout<<endl;
    //     return ptr[ofindex];
    // }
    // else{
    //     cout<<"invalid index ";
    //    throw new exception();
    // }
    if (ofindex < 0 || lastindex < ofindex)
    {
        cout << "invalid index" << endl;
        throw new exception();
    }
    else
    {
        return ptr[ofindex];
    }
}
int Array::countElement()
{
    return lastindex + 1;
}
int Array::findElement(int element)
{

    for (int i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Array::~Array()
{
    delete[] ptr;
}
int main()
{
    Array a1(8);
    a1.append(5);
    a1.append(6);
    a1.append(7);
    a1.append(8);
    a1.append(9);
    a1.showArray();
}