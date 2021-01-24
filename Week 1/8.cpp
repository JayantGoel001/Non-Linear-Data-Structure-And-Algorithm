#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        data = 0;
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
    Node *tail = curr;
    curr->next = head;
    cout<<"Enter The Value from where it is to be split:\n";
    int k;
    cin>>k;

}