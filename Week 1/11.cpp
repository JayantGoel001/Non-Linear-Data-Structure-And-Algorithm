#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        next = nullptr;
    }
    explicit Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
int main(){
    int n;
    cout<<"Enter Number of Elements in List:\n";
    cin>>n;
    Node *head = nullptr;
    Node *curr = head;
    cout<<"Enter Elements in Circular Linked List :\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (curr) {
            curr->next = temp;
            curr = curr->next;
        } else{
            curr = temp;
            head = temp;
        }
    }

    Node *temp = head;
    Node *prev = nullptr;
    Node *firstHead = nullptr;
    Node *secondHead = nullptr;
    while (temp){
        if (prev && temp->data<prev->data){
            firstHead = head;
            secondHead = temp;

            prev->next = nullptr;
            break;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    Node *merged = nullptr;
    Node *cur = merged;
    while (firstHead!= nullptr && secondHead!= nullptr){
        int data;
        if (firstHead->data<secondHead->data){
            data = firstHead->data;
            firstHead = firstHead->next;
        } else{
            data = secondHead->data;
            secondHead = secondHead->next;
        }
        if (cur){
            cur->next = new Node(data);
            cur = cur->next;
        } else{
            cur = new Node(data);
            merged = cur;
        }
    }
    while (firstHead){
        if (cur){
            cur->next = new Node(firstHead->data);
            cur = cur->next;
        } else{
            cur = new Node(firstHead->data);
            merged = cur;
        }
        firstHead = firstHead->next;
    }
    while (secondHead){
        if (cur){
            cur->next = new Node(secondHead->data);
            cur = cur->next;
        } else{
            cur = new Node(secondHead->data);
            merged = cur;
        }
        secondHead = secondHead->next;
    }
    while (merged){
        cout<<merged->data;
        if (merged->next){
            cout<<"->";
        }
        merged = merged->next;
    }
}