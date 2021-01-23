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
    cout<<"Enter Number of Elements:\n";
    cin>>n;
    Node *head = nullptr;
    Node *cur = head;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (cur) {
            cur->next = temp;
            cur = cur->next;
        } else{
            head = temp;
            cur = temp;
        }
    }
    Node *temp =head;
    while (temp!= nullptr && temp->next!= nullptr){
        swap(temp->data,temp->next->data);
        temp= temp->next->next;
    }

    temp = head;
    while (temp!= nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}