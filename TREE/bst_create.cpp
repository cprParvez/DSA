// Assignment-1 : code to create a BST from an array of size N
#include <bits/stdc++.h>
using namespace std;

// for creating node
class Node {
    public:
        int data;
        Node *left;
        Node *right;

        // for creating new node
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

// to insert node in the BST
Node *insert(Node *root, int val) {
    // base case : when reach leaf node, insert the new node
    if(root == NULL) {
        return new Node(val);
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

// to print the BST
void cop(Node *root) {
    if(root != NULL) {
        cop(root->left);
        cout << root->data << " ";
        cop(root->right);
    }
}

// to input array of size N
void cip(int *a, int n) {
    cout << "Enter " << n << " elements : ";
    for(int i=0; i<n; i++)
        cin >> a[i];
}

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    // declaring array of size N
    int a[n];
    cip(a, n);          // call for input array


    Node *root=NULL;
    // to create BST using elements of array A
    for(int i=0; i<n; i++) {
        if(root == NULL)
            root = insert(root, a[i]);
        else
            insert(root, a[i]);
    }

    cop(root);          // print BST
    return 0;
}