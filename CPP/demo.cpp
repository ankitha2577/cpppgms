#include "array.cpp"
int main()
{
    my_array<int> obj1;
    my_array<string> obj2;
    cout<<"Integer array"<<endl;
    obj1.displaymy_array();
    cout<<endl<<"String array"<<endl;
    obj2.displaymy_array();
    return 0;
}