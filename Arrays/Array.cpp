
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
    bool isEmpty();
    void appendArray(int);
    void showArray();
    void atSpecificIndex(int, int);
    void editElement(int,int);
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
bool Array::isEmpty()
{
    return (lastindex == -1);
}
void Array::appendArray(int data)
{
    if (lastindex < capacity - 1)
    {
        ++lastindex;
        ptr[lastindex] = data;
        // cout<<endl<<lastindex<<" = "<<ptr[lastindex];
    }
    else
    {
        cout << "Array is out of bound"<<endl;
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
    if (lastindex < capacity-1)
    {

        if (atindex > -1 && atindex < capacity)
        {

            if (atindex > lastindex)
            {
                ++lastindex;
                ptr[lastindex] = data;
            }
            else
            {
                ++lastindex;
                for (int i = lastindex; i > atindex; i--)
                {
                    ptr[i] = ptr[i - 1];
                }
                ptr[atindex] = data;
            }
        }
        else
        {
            cout << "Array out of bound"<<endl;
        }
    }
    else
    {
        cout << "array is full"<<endl;
    }
}
void Array::editElement(int atindex,int data){
    if(atindex>-1&&atindex<=lastindex){
       ptr[atindex]=data;
    }
    cout<<"array out of bound "<<endl;
}
void Array::deleteIndexAt(int atindex){
        if (lastindex>-1&&lastindex>=atindex)
        {
            if (lastindex==0)
            {
                lastindex=-1;
            }
            else{
                for (int i = atindex; i <lastindex; i++)
                {
                    ptr[i]=ptr[i+1];
                }
                lastindex--;
                
            }
        }
        else{
            cout<<"invalid index"<<endl;
        }
        
}
bool Array::isFull(){
    cout<<endl;
 return (lastindex==capacity-1);
    
}
int Array::getElement(int ofindex){
        if (ofindex>-1&&lastindex>=ofindex)
        {
            cout<<endl;
            return ptr[ofindex];
        }
        else{
            cout<<"invalid index ";
            return -1;
        }
        
}
int Array::countElement(){
    return lastindex+1;
}
int Array::findElement(int element){
    if (lastindex==-1)
    {
        return -1;
    }
    else{
        for(int i=0;i<=lastindex;i++){
            if (ptr[i]==element)
            {
                return i;
            }
           
            
        }
         return -1;

    }
    
}
Array::~Array()
{
    delete ptr;
}
int main()
{
    
    return 0;
}