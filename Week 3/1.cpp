#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *npx;
    Node(){
        this->data = 0;
        this->npx = nullptr;
    }
    Node(int data){
        this->data = data;
        this->npx = nullptr;
    }
};
Node *XOR(Node *a,Node *b){
    return (Node*)((uintptr_t)(a)^(uintptr_t)(b));

}
Node* insert(Node *head,int data){
    Node *temp = new Node(data);
    temp->npx = head;

    if (head!= nullptr){
        head->npx = XOR(temp,head->npx);
    }
    head = temp;
    return head;
}
void printList(Node *head){
    if (!head){
        return;
    }
    cout<<"In Forward Direction:\n";
    Node *temp = head;
    Node *prev = nullptr;
    while (true){
        cout<<temp->data<<" ";
        Node *next = XOR(prev,temp->npx);
        prev = temp;
        if (!next){
            break;
        }
        temp = next;
    }
    cout<<"\n\nIn Backward Direction:\n";

    Node *next = nullptr;
    while (temp!= nullptr){
        cout<<temp->data<<" ";
        prev = XOR(next,temp->npx);
        next = temp;
        temp = prev;
    }

}
int main(){
    int n;
    cout<<"Enter the value of N:\n";
    cin>>n;
    Node *head = nullptr;
    for (int i = 0; i < n; ++i) {
        int data;
        cin>>data;
        head = insert(head,data);
    }
    printList(head);
}