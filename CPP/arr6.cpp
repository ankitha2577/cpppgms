/* insertion at begining,end and at position using an array three programs for each, getting input from the user.
   Beginner-friendly program; no classes or additional libraries. */
   #include <iostream>
   using namespace std;
   int main()
   {
         int n, arr[100], choice, pos, value;
    
          cout << "Enter the number of elements: ";
          cin >> n;
    
          cout << "Enter " << n << " elements:" << endl;
          for (int i = 0; i < n; i++)
          {
                cin >> arr[i];
          }
    
          cout << "Choose an insertion option:\n";
          cout << "1. Insert at the beginning\n";
          cout << "2. Insert at the end\n";
          cout << "3. Insert at a specific position\n";
          cin >> choice;
    
          switch (choice)
          {
                case 1:
                 cout << "Enter the value to insert at the beginning: ";
                 cin >> value;
                 for (int i = n; i > 0; i--)
                 {
                      arr[i] = arr[i - 1];
                 }
                 arr[0] = value;
                 n++;
                 break;
    
                case 2:
                 cout << "Enter the value to insert at the end: ";
                 cin >> value;
                 arr[n] = value;
                 n++;
                 break;
    
                case 3:
                 cout << "Enter the position (0 to " << n << ") to insert: ";
                 cin >> pos;
                 if (pos < 0 || pos > n)
                 {
                      cout << "Invalid position!" << endl;
                      return 1;
                 }
                 cout << "Enter the value to insert at position " << pos << ": ";
                 cin >> value;
                 for (int i = n; i > pos; i--)
                 {
                      arr[i] = arr[i - 1];
                 }
                 arr[pos] = value;
                 n++;
                 break;
    
                default:
                 cout << "Invalid choice!" << endl;
                 return 1;
          }
    
          cout << "Array after insertion:" << endl;
          for (int i = 0; i < n; i++)
          {
                cout << arr[i] << " ";
          }
          cout << endl;
    
          return 0;
     }