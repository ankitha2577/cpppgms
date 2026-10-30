
#include <iostream>
using namespace std;

int main()
{
    int  n ,key,mid,low,high,arr[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements in sorted order: ";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;
    low=0;
    high=n-1;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(arr[mid]==key)
        {
            cout<<key<<" found at position "<<mid+1<<endl;
            break;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        mid=(low+high)/2;
    }
}
 
