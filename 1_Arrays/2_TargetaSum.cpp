#include<iostream>
using namespace std;
int targetSum(int arr[],int target){
    int length=11;
    
    for (int i = 0;i<length; i++)
    {
            cout<<arr[i]<<" ";
    }
    cout<<"length = "<<length<<endl;
    
    int pair=0;
    for (int i = 0; i < length; i++)
    {
        for (int j=i+1; j < length; j++)
        {
            if (arr[i]+arr[j]==target)
            {
                ++pair;
            }
            
        }
        
    }
    return pair;
    
}
int main()
{
    int arr[11]={5,2,4,6,5,9,1,3,7,8,2};
    
    cout<<targetSum(arr,10);
    

    return 0;
}