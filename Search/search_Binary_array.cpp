// code for Binary Search algorithm to find element in array

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

// Binary Search Algorithm
int searchBinary(int *arr, int n, int val) {
            sort(arr, arr+n);                       // sorting array for binary search

            int midIndx, fIndx=0, lIndx=n-1;
            while (fIndx <= lIndx)
            {
                midIndx = fIndx + (lIndx-fIndx)/2;
                if(arr[midIndx] == val) {
                    return midIndx;
                }
                else if(val > arr[midIndx])
                    fIndx = midIndx+1;
                else
                    lIndx = midIndx-1;
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
    (searchBinary(a, n, val) == -1) ? cout << "No" << endl : cout << "YES" << endl;
    return 0;
}