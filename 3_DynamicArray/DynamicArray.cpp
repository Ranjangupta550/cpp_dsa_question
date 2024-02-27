#include <iostream>
using namespace std;

class DynArray
{
public:
    int capacity;
    int lastindex;
    int *ptr;
    protected:
     void doubleSize();
    void halfSize();

public:
  
    DynArray(int);
   
    void appendArray(int);
    bool isFull();
    bool isEmpty();
    int currentCapacity();
    void showArray();
    int countElement();
    void atSpecificIndex(int ,int);
    void delet(int);

    ~DynArray();
};


DynArray::DynArray(int capacity)
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

void DynArray ::doubleSize(){
    int *temp=new int [capacity*2];
    for (int i = 0; i <= lastindex; i++)
    {
        temp[i]=ptr[i];
    }
    this->capacity=capacity*2; 
    delete[]ptr;
    ptr=temp;
    
}
void DynArray::halfSize(){
    int *temp=nullptr;
    if (capacity%2)
    {
        this->capacity=(capacity/2)+1; 
        temp=new int  [capacity];
    }
    else{
        this->capacity=capacity/2;
        temp=new int[capacity];
    }
    if (lastindex>capacity)
    {
        lastindex=capacity-1;
    }
    else{
        this->lastindex=lastindex;
    }
    for(int i=0;i<=lastindex;i++){
        temp[i]=ptr[i];
    }
 
    delete []ptr;
    ptr=temp;
    
}
int DynArray::countElement(){
    return lastindex+1;
}

bool DynArray::isFull(){
    return (lastindex+1==capacity);
}
bool DynArray::isEmpty(){
    return (lastindex==-1);
}
void DynArray::appendArray(int data){


    if (isFull())
    {
        doubleSize();
        ++lastindex;
        ptr[lastindex]=data;

    }
    else{
        ++lastindex;
        ptr[lastindex]=data;
    }
    
}
void DynArray::atSpecificIndex(int atindex, int data)
{
    if (atindex < 0||atindex>lastindex+1 )
    {
        cout << "array out of bound" << endl;
    }
    else
    {
        if(isFull()){
             doubleSize();
        }
       
        for (int i = lastindex; i >= atindex; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[atindex] = data;
        lastindex++;
    }
   
    
}
int DynArray::currentCapacity(){
    return capacity;
}
void DynArray::showArray()
{
    for (int i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }
}
void DynArray::delet(int index){
        if (index<0||index>lastindex)
        {
            cout<<"invalid index";
        }
        else{
            for (int i = index; i < lastindex; i++)
            {
                ptr[i]=ptr[i+1];
            }
            lastindex--;
            if (capacity>1&&lastindex+1<=capacity)
            {
             halfSize();
            }
            
        }
}
DynArray::~DynArray()
{
    delete []ptr;
}

int main()
{
    DynArray a1(10);
    a1.appendArray(1);
    a1.appendArray(2);
    a1.appendArray(3);
    a1.appendArray(4);
    a1.appendArray(5);
    a1.atSpecificIndex(10,6);
    a1.atSpecificIndex(12,6);
   
    
    a1.showArray();

    return 0;
}