#include <iostream>
using namespace std;
class linkedlist
{
private:
struct node
{
int data;
node *link;
}*start,*newnode,*temp;//structure variable
public:
linkedlist();// default constructor
void insert();// function prototype
void display();

};
linkedlist::linkedlist()//constructor definition outside the class
{
    start=NULL; //initializing head node to empty
}
void linkedlist ::insert()
{
    int num;
    char ch='y';
    do //works till user enters other than y
    {
        cout<<"enter the number";
        cin>>num;
        newnode=new node;//creating a node 
        newnode->data=num; //assign value to node
        newnode->link=NULL;// assign pointer part as null
        cout<<"START"<<"\n";
        if (start==NULL)// run if list is empty
        {
        start=temp=newnode;// point to start, then temp to node
        }
        else 
        {
          temp->link=newnode;
          temp= newnode;


        }
      cout<<"do you want to continue?";
      cin>>ch;
    } while(ch=='y');
}
void linkedlist::display()
{
    temp=start;// pointing to start node
    if (start==NULL)
    {
        cout<<"linked list is empty"<<"\n";
    }
    else
    {
        while (temp!=NULL)
        {
            cout<<temp->data<<"\n";
            temp=temp->link;
        }
        cout<<"end\n";
    }
}
int main()
{
 linkedlist obj;
 
 obj.insert();
 obj.display();
 
 return 0;

}
