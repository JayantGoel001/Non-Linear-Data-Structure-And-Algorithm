#include <iostream>
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
    Node *head = nullptr;
    Node *curr = head;
    cout<<"Enter Elements in List 1:\n";
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
    Node *tail = head;
    Node *temp = head;
    while (temp->next!= nullptr){
        temp = temp->next;
    }
    tail = temp;
    int k;
    cout<<"Enter The value of K:\n";
    cin>>k;
    while (k && head!= nullptr){
        Node *tempNext = head->next;
        head->next = nullptr;
        tail->next = head;
        tail = tail->next;
        head = tempNext;
        k--;
    }

    Node *printOutput = head;
    while (printOutput){
        cout<<printOutput->data<<" ";
        printOutput = printOutput->next;
    }
}