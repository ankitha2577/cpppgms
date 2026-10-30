
#include <iostream>
using namespace std;

int main()
{
    int n, key, found= -1,arr[100];

    cout << "Enter the number of elements: ";
    cin >> n;

   

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = i + 1;
            break;
        }
    }

    if (found != -1)
    {
        cout << key << " found at position " << found << endl;
    }
    else
    {
        cout << key << " not found" << endl;
    }

    return 0;
}
