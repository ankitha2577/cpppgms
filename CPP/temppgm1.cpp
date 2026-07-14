#include<iostream>
using namespace std;

template <class T>

    T Large(T n1, T n2)
    {
        return (n1>n2)?n1:n2;
    }


int main() {
    
    std::cout << Large(3, 5) << endl;
    std::cout << Large(3.5, 2.5) << endl;
    std::cout << Large('A', 'B') << endl;

    return 0;
}

