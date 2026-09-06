// array.h
#include <iostream>
using namespace std;
 
template <class T>
class myarray
{
    int lb, ub;   
    T a[100];     
 
    public:
    myarray();                              
    void setLB(int x);                    
    void setUB(int x);                    
    int  getLB();                         
    int  getUB();                         
    void create();                        
 
    // Searching Algorithms
    int linear_search(T key);
    int binary_search(T key);

    // Sorting Algorithms
    void bubble_sort();
    void insertion_sort();
    void selection_sort();
    void quick_sort(int low, int high);
    int partition(int low, int high);
    void merge_sort(int low, int high);
    void merge(int low, int mid, int high);
 
    template<class U> friend ostream& operator<<(ostream&, const myarray<U>&);
};