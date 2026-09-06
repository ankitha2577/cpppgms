// demo.cpp
#include "array.cpp"
 
int main()
{
    char repeat;
    int choice;
    int l, u, ele, result;
    myarray<int> arr; // Created our box using 'myarray'
 
    do
    {
        cout << "\n\t SEARCH & SORT MENU" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. Create an array with user input" << endl;
        cout << "2. Linear Search" << endl;
        cout << "3. Binary Search (Array must be sorted first!)" << endl;
        cout << "4. Bubble Sort" << endl;
        cout << "5. Insertion Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Quick Sort" << endl;
        cout << "8. Merge Sort" << endl;
        cout << "9. Display the array elements" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice)
        {
            case 1:
                cout << "Enter the lower bound: ";
                cin >> l;
                arr.setLB(l);
                cout << "Enter the upper bound: ";
                cin >> u;
                arr.setUB(u);
                arr.create();
                break;
 
            case 2:
                cout << "Enter the element to search for: ";
                cin >> ele;
                result = arr.linear_search(ele);
                if (result != -1) cout << "Element found at index: " << result << endl;
                else cout << "Element not found!" << endl;
                break;
 
            case 3:
                cout << "Enter the element to search for: ";
                cin >> ele;
                result = arr.binary_search(ele);
                if (result != -1) cout << "Element found at index: " << result << endl;
                else cout << "Element not found!" << endl;
                break;
 
            case 4:
                arr.bubble_sort();
                cout << "Array sorted using Bubble Sort!" << endl;
                break;
 
            case 5:
                arr.insertion_sort();
                cout << "Array sorted using Insertion Sort!" << endl;
                break;
 
            case 6:
                arr.selection_sort();
                cout << "Array sorted using Selection Sort!" << endl;
                break;
 
            case 7:
                arr.quick_sort(arr.getLB(), arr.getUB());
                cout << "Array sorted using Quick Sort!" << endl;
                break;

            case 8:
                arr.merge_sort(arr.getLB(), arr.getUB());
                cout << "Array sorted using Merge Sort!" << endl;
                break;
 
            case 9:
                cout << arr;   
                break;
 
            default:
                cout << "Invalid entry" << endl;
        }
 
        cout << "Do you want to continue (y/n)? ";
        cin >> repeat;
 
    } while (repeat == 'y' || repeat == 'Y');
 
    return 0;
}