// code for linearSearch Search Algorthm to find element in array

#include <bits/stdc++.h>
using namespace std;

// to input array
void cip(int *arr, int size) {
    cout << "Enter " << size << " elements : ";
    for(int i=0; i<size; i++)
        cin >> arr[i];
}

// to print array
void cop(int *arr, int size) {
    cout << "Array elements are : ";
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Linear Search Algorithm
int linearSearch(int *arr, int n, int val) {
            for(int i=0; i<n; i++) {
                if(arr[i] == val) {
                    return i;
                }
            }
            return -1;
        }

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    int a[n];
    cip(a, n);

    int val;
    cout << "Enter the Value : ";
    cin >> val;
    (linearSearch(a, n, val) == -1) ? cout << "No" : cout << "Yes";
    cout << endl;
    return 0;
}