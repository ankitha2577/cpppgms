
#include "array.h"
 

template <class T> void myarray<T>::setLB(int x) { lb = x; }
template <class T> void myarray<T>::setUB(int x) { ub = x; }
template <class T> int myarray<T>::getLB() { return lb; }
template <class T> int myarray<T>::getUB() { return ub; }
 
template <class T>
myarray<T>::myarray() {
    lb = 1;
    ub = 0;
    for (int i = lb; i <= ub; i++) a[i] = 0;
}
 
template <class T>
void myarray<T>::create() {
    cout << "Enter the elements: ";
    for (int i = lb; i <= ub; i++) cin >> a[i];
}

template <class U>
ostream& operator<<(ostream& os, const myarray<U>& m) {
    os << endl;
    for (int i = m.lb; i <= m.ub; i++) os << m.a[i] << " ";
    os << endl;
    return os;   
}

// Searching Algorithms 

template <class T>
int myarray<T>::linear_search(T key) {
    for (int i = lb; i <= ub; i++) {
        if (a[i] == key) return i; 
    }
    return -1; 
}

template <class T>
int myarray<T>::binary_search(T key) {
    int left = lb;
    int right = ub;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1; 
}

//  Sorting Algorithms 

template <class T>
void myarray<T>::bubble_sort() {
    for (int i = lb; i <= ub - 1; i++) {
        for (int j = lb; j <= ub - 1 - (i - lb); j++) {
            if (a[j] > a[j + 1]) {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template <class T>
void myarray<T>::insertion_sort() {
    for (int i = lb + 1; i <= ub; i++) {
        T key = a[i];
        int j = i - 1;
        while (j >= lb && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

template <class T>
void myarray<T>::selection_sort() {
    for (int i = lb; i < ub; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= ub; j++) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        T temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

// Quick Sort (Lomuto Partition) 

template <class T>
int myarray<T>::partition(int low, int high) {
    T pivotValue = a[high];   
    int i = low - 1;          
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivotValue) {
            i++;
            T temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    T temp2 = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp2;
    return i + 1; 
}

template <class T>
void myarray<T>::quick_sort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quick_sort(low, pivotIndex - 1);  
        quick_sort(pivotIndex + 1, high); 
    }
}

// Merge Sort 

template <class T>
void myarray<T>::merge(int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    T L[100], R[100]; 
    
    for (int i = 0; i < n1; i++) L[i] = a[low + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
    
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { a[k] = L[i]; i++; } 
        else { a[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { a[k] = L[i]; i++; k++; }
    while (j < n2) { a[k] = R[j]; j++; k++; }
}

template <class T>
void myarray<T>::merge_sort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        merge_sort(low, mid);        
        merge_sort(mid + 1, high);   
        merge(low, mid, high);       
    }
}