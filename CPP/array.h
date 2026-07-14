#include<iostream>
#include<string>
using namespace std;
template <class T>
class my_array
{
    T a[100];
    int lb,ub;
    public:
    my_array();
    
    void displaymy_array();
};