#include "array.cpp"
 
int main()
{
    char repeat;
    int choice;
    int pos, ele, l, u;
    myarray<int> arr;
 
    do
    {
        cout << "\t\t Menu" << endl;
        cout << "----------" << endl;
        cout << "1.create an array with user input" << endl;
        cout << "2.insertion at beginning" << endl;
        cout << "3.insertion at a specific position" << endl;
        cout << "4.Insertion at end" << endl;
        cout << "5.Deletion from beginning" << endl;
        cout << "6.Deletion at specific position" << endl;
        cout << "7.Deletion from end" << endl;
        cout << "8.Display the array elements" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
 
        switch (choice)
        {
            case 1:
                cout << "Enter the lower bound" << endl;
                cin >> l;
                arr.setLB(l);
                cout << "enter the upper bound" << endl;
                cin >> u;
                arr.setUB(u);
                arr.create();
                break;
            case 2:
                cout << "Enter the element" << endl;
                cin >> ele;
                arr.insert_at_beginning(ele);
                break;
            case 3:
                cout << "enter the position(" << arr.getLB() << "--" << arr.getUB() << ")";
                cin >> pos;
                cout << "Enter the element" << endl;
                cin >> ele;
                arr.insert_at_position(pos, ele);
                break;
            case 4:
                cout << "Enter the element" << endl;
                cin >> ele;
                arr.insert_at_end(ele);
                break;
            case 5:
                arr.delete_at_beginning();
                break;
            case 6:
                cout << "enter the position(" << arr.getLB() << "--" << arr.getUB() << ")";
                cin >> pos;
                arr.delete_at_position(pos);
                cout << "element deleted" << endl;
                break;
            case 7:
                arr.delete_at_end();
                break;
            case 8:
                cout << arr;   
                break;
            default:
                cout << "Invalid entry" << endl;
        }
 
        cout << "Do you want to continue(y/n)" << endl;
        cin >> repeat;
 
    } while (repeat == 'y');
 
    return 0;
}