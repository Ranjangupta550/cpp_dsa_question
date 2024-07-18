#include<iostream>
using namespace std;
int main()
{
    int rear=-1;
    int ptr[5]={1,3,4,5,6};
    cout<<rear<<endl;//-1
    ++rear;
    cout<<rear;
    ptr[rear]=7;
    cout<<ptr[rear];//7;

    return 0;
}