#include<iostream>
using namespace std;
template <class T>
class calculator
{
   private: T num1, num2;
   public:
   calculator(T n1, T n2)
   {
       num1 = n1;
       num2 = n2;
   }
   T add ()
   {
       return num1 + num2;
   }
};
int main()
{
    calculator <int> obj1(3, 5);
    calculator <double> obj2(3.5, 2.6);
    calculator <double> obj3(3.5, 2.5);
    calculator <string> obj4("Hello, ", "World!");
    cout << obj1.add() << endl;
    cout << obj2.add() << endl;
    cout << obj3.add() << endl;
    cout << obj4.add() << endl;
    return 0;
}