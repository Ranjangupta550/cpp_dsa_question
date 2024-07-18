#include <iostream>

using namespace std;

class Searching
{
public:
    int BinarySearchrecursive(int *, int, int, int);
    int BinarySearchiterative(int *, int, int);
};
//code 1->>
int Searching::BinarySearchrecursive(int *arr, int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        if (key < arr[mid])
        {
            high = mid - 1;
            return BinarySearchrecursive(arr, low, high, key); 
        }
        else
        {
            low = mid + 1;
            return BinarySearchrecursive(arr, low, high, key);
        }
    }
    return -1;
}
int Searching::BinarySearchiterative(int *arr,int high,int key){
    int low=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (key==arr[mid])
        {
           return mid;
        }
        if (key<arr[mid]){
            high=mid-1;
           
        }
       else{
            low=mid+1;
       }
    }
    return -1;
}

int main()
{
   int arr[] = {6,90};
    int size = sizeof(arr) / sizeof(arr[0]);
    Searching s;
    cout<<s.BinarySearchrecursive(arr, 0, size - 1, 6);
 
    return 0;

}
