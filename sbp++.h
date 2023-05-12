#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node *temp, *newNode;
class List {
public:
    int size(Node *head) {
        int cnt=0;
        temp = head;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void in(Node* &head, int val, int pos=INT_MAX, int size=0) {
        if(pos<=0) {
            cout << "Invalid Position" << endl;
            return;
        }
        
        newNode = new Node(val);
        temp = head;
        if(head == NULL) {
            head = newNode;
            return;
        }
        if(pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        if(pos>1 && pos<size) {
            for(int i=1; i<pos; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void del(Node* &head, int pos=INT_MAX, int size=0) {
        temp = head;
        if(head == NULL) {
            cout << "EMPTY LIST!" << endl;
            return;
        }

        if(head->next == NULL) {
            free(head);
            return;
        }

        if(pos == 1) {
            head = head->next;
            free(temp);
            return;
        }

        if(pos>1 && pos<size) {
            for(int i=2; i<pos; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node *toDel = temp->next->next;
        temp->next = NULL;
        free(toDel);
        
    }

    void delVal(Node* &head, int val) {
        temp = head;
        if(head == NULL) {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        
        if(head->data == val) {
            head = head->next;
            free(temp);
            return;
        }

        while (temp->next != NULL)
        {
            if(temp->next->data == val) {
                temp->next = temp->next->next;
                free(temp->next);
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid operation!" << endl;
    }

    void out(Node *head) {
        if(head == NULL) {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        temp=head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};