#include<iostream>
using namespace std;


void merge(int arr[], int lb, int mid, int ub) {
    int temp[100]; // Using a simple array for temporary storage
    int i = lb;
    int j = mid + 1;
    int k = lb;
    
    // Compare and merge the two halves into temp[]
    while(i <= mid && j <= ub) {
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    // If the left half is exhausted, copy the rest of the right half
    if(i > mid) {
        while(j <= ub) {
            temp[k] = arr[j];
            j++;
            k++; 
        }
    } 
    
    // If the right half is exhausted, copy the rest of the left half
    else { 
        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    
    // Copy the merged elements from temp[] back into the original arr[]
    for(k = lb; k <= ub; k++) {
        arr[k] = temp[k];
    }
  
}


void mergesort(int arr[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

// The main function 
int main(){
    int arr[100], lb, ub;
    
    cout << "enter value of lower bound" << endl;
    cin >> lb;
    
    cout << "enter value of upper bound" << endl;
    cin >> ub;
    
    cout << "enter elements" << endl;
    for(int i = lb; i < ub; i++){
        cin >> arr[i];
    }
    
    cout << "displaying array" << endl;
    for(int i = lb; i < ub; i++){
        cout << arr[i] << " ";
    }
    
    // Call mergesort passing ub-1 since the loop above takes elements up to ub-1
    mergesort(arr, lb, ub - 1);
    
    cout << "\n after sorting \n";
   
    for(int i = lb; i < ub; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}