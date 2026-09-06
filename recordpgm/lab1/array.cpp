#include "array.h"
 
template <class T>
void myarray<T>::setLB(int x) { lb = x; }
 
template <class T>
void myarray<T>::setUB(int x) { ub = x; }
 
template <class T>
int myarray<T>::getLB() { return lb; }
 
template <class T>
int myarray<T>::getUB() { return ub; }
 
template <class T>
myarray<T>::myarray()
{
    lb = 1;
    ub = 0;
    for (int i = lb; i <= ub; i++)
        a[i] = 0;
}
 
template <class T>
void myarray<T>::create()
{
    int i;
    cout << "enter the elements";
    for (i = lb; i <= ub; i++)
        cin >> a[i];
}
 
template <class T>
void myarray<T>::insert_at_beginning(T key)
{
    for (int i = ub; i >= lb; i--)
    {
        a[i + 1] = a[i];
    }
    a[lb] = key;
    ub = ub + 1;
}
 
template <class T>
void myarray<T>::insert_at_end(T key)
{
    int pos = ub + 1;
    a[pos] = key;
    ub = ub + 1;
}
 
template <class T>
void myarray<T>::insert_at_position(int p, T key)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
        return;
    }
    for (int i = ub; i >= p; i--)
    {
        a[i + 1] = a[i];
    }
    a[p] = key;
    ub = ub + 1;
}
 
template <class T>
void myarray<T>::delete_at_end()
{
    ub = ub - 1;
}
 
template <class T>
void myarray<T>::delete_at_beginning()
{
    for (int i = lb; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
 
template <class T>
void myarray<T>::delete_at_position(int p)
{
    if (p > ub || p < lb)
    {
        cout << "invalid position" << endl;
        return;
    }
    for (int i = p; i <= ub - 1; i++)
    {
        a[i] = a[i + 1];
    }
    ub = ub - 1;
}
 
template <class U>
ostream& operator<<(ostream& os, const myarray<U>& m)
{
    int i;
    os << endl;
    for (i = m.lb; i <= m.ub; i++)
        os << m.a[i] << " ";
    os << endl;
    return os;   
}