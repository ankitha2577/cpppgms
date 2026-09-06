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
    void insert_at_end(T key);            
    void insert_at_beginning(T key);      
    void insert_at_position(int, T key);  
    void delete_at_end();                 
    void delete_at_beginning();           
    void delete_at_position(int);         
 
    template<class U> friend ostream& operator<<(ostream&, const myarray<U>&);
};