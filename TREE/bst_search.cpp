// Assignment-1 : code for searching a element in BST
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
    // base case : when reach the leaf node, insert the new node
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

// to searching an element in BST
Node *search(Node *root, int key) {
    // base case : when reach leaf node, but key didn't match -> return NULL
    if(root == NULL) {
        return NULL;
    }

    if(key == root->data) {
        return root;
    }
    else if(key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
    return 0;
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
    cout << endl;

    int key;
    cin >> key;
    cout << "Enter key for search : ";
    // to check search result
    search(root, key) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}