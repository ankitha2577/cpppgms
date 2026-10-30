/* deletion at begining,end and at position using an array three programs for each, getting input from the user.
   Beginner-friendly program; no classes or additional libraries. */
#include <iostream>
using namespace std;
int main()
{
    int n, arr[100], choice, pos;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Choose a deletion option:\n";
    cout << "1. Delete from the beginning\n";
    cout << "2. Delete from the end\n";
    cout << "3. Delete from a specific position\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            for (int i = 0; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        case 2:
            n--;
            break;

        case 3:
            cout << "Enter the position (0 to " << n - 1 << ") to delete: ";
            cin >> pos;
            if (pos < 0 || pos >= n)
            {
                cout << "Invalid position!" << endl;
                return 1;
            }
            for (int i = pos; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            break;

        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "Array after deletion:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}