#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data =0;
        this->next = nullptr;
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
    Node *first = nullptr;
    Node *curr = first;
    cout<<"Enter Elements in List 1:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (curr) {
            curr->next = temp;
            curr = curr->next;
        } else{
            first = temp;
            curr = temp;
        }
    }
    Node *second= nullptr;
    curr = second;
    cout<<"Enter Elements in List 2:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (curr) {
            curr->next = temp;
            curr = curr->next;
        } else{
            curr = temp;
            second = temp;
        }
    }

    Node *temp1 = first;
    Node *temp2 = second;

    while (temp1!= nullptr && temp2!= nullptr){
        Node* temp = temp1->next;
        temp1->next = new Node(temp2->data);
        temp1 = temp1->next;
        temp1->next = temp;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }

    Node *temp = first;
    while (temp!= nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}