#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
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
    Node *tail = head;
    while (temp->next!= nullptr){
        temp = temp->next;
    }
    tail = temp;
    Node *end = tail;
    while (head && head!=end){
        Node *tempo = new Node(head->data);
        if (tail->next){
            tempo->next = tail->next;
        }
        tail->next = tempo;
        head = head->next;
    }
    while (head){
        cout<<head->data;
        if (head->next){
            cout<<"->";
        }
        head = head->next;
    }
}