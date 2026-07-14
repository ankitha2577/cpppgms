#include<iostream>
#include<string>
using namespace std;
template <class T>
class array_operation
{
    private:
       T a[100];
       int n;
    public:
    void readdata();
    T findarraysuum(T a);
    void display();
};
template <typename T> 
void array_operation<T>::readdata()
{
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}
template <typename T>
void array_operation<T>::display()
{
    cout << "The elements are: ";
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
   
}
template <typename T> T array_operation<T>::findarraysuum(T key)
{
    int i,s;
    for(i=0; i<n; i++)
    {
       s+=a[i]+key;

    }
    return s;
}
int main()
{
    array_operation<int> obj1;
    obj1.readdata();
    obj1.display();
    cout<<endl;
   cout<<"array sum"<<endl << obj1.findarraysuum(5)<<endl;
    return 0;
}