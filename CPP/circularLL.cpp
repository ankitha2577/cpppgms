#include <iostream>
using namespace std;

// 1. Define the node 
struct node 
{
    int data;            //
    struct node *link;   //
};

// Global tracking pointers from the image
struct node *tail = NULL;    //[cite: 13]
struct node *newnode = NULL; //[cite: 13]
struct node *temp = NULL;    //[cite: 13]

// 2. add a node to the end of the circle
void insertend(int num)      
{
    // Create  new node
    newnode = new node;
    newnode->data = num;
    newnode->link = NULL;

    if (tail == NULL) 
    {
        // If the list is empty, this single node forms a circle with itself!
        tail = newnode;
        tail->link = tail; // It points to itself
    } 
    else 
    {
        // Add the new node to the circle
        newnode->link = tail->link; // 1. New node points to the first node
        tail->link = newnode;       // 2. Old last node points to the new node
        tail = newnode;             // 3. The new node becomes the official tail
    }
}

//   print the circle
void display()               
{
    if (tail == NULL) 
    {
        cout << "List is empty.\n";
    } 
    else 
    {
        // Start at the first node (which is tail->link)
        temp = tail->link;
        
        cout << "Circular Linked List: ";
        
        // do-while loop run until it circles back
        do 
        {
            cout << temp->data << " -> ";
            temp = temp->link;             // Move to the next node
            
        } while (temp != tail->link);      // Stop when we reach the first node again
        
        cout << "(back to start)\n";
    }
}

//  Main program 
int main() 
{
    // Add numbers to circular list
    insertend(10);
    insertend(20);
    insertend(30);

    // Print the list 
    display();

    return 0;
}
