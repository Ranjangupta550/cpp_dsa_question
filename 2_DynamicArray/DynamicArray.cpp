#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    DynamicArray();
    DynamicArray(int);
    void doubleSize();
    void appendArray(int);
    ~DynamicArray();
};

DynamicArray::DynamicArray()
{

    this->capacity = 10;
    this->lastindex = -1;
    ptr = new int[capacity];
}

DynamicArray::DynamicArray(int capacity)
{

    if (capacity >= 0)
    {
        this->capacity = capacity;
        this->lastindex = -1;
        ptr = new int[capacity];
    }
    else
    {
        cout << "invalid capacity" << endl;
    }
}
void DynamicArray::appendArray(int data){
   if (lastindex<capacity-1)
   {
     ++lastindex;
     ptr[lastindex]=data;
   }
   
    
}
void DynamicArray ::doubleSize(){

}

DynamicArray::~DynamicArray()
{
}

int main()
{

    return 0;
}