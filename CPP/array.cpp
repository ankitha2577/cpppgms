#include "array.h"
template <class T>
my_array<T>::my_array()
{
    cout << "Enter the lower bound: ";
    cin >> lb;
    cout << "Enter the upper bound: ";
    cin >> ub;
    for(int i=lb; i<=ub; i++)
    {
        
        cin >> a[i];
    }
}
template <class T>
void my_array<T>::displaymy_array()
{
    cout << "The elements are: ";
    for(int i=lb; i<=ub; i++)
    {
        cout << a[i] << " ";
    }
}