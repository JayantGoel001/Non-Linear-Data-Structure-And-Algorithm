#include <iostream>
using namespace std;
class DoublyLinkedListNode{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode(){
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    DoublyLinkedListNode(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
int main(){
    int n;
    cout<<"Enter the value of N:\n";
    cin>>n;
    DoublyLinkedListNode *head = nullptr;
    DoublyLinkedListNode *curr = head;
    for (int i = 0; i < n; ++i) {
        int data;
        cin>>data;
        DoublyLinkedListNode *temp = new DoublyLinkedListNode(data);
        if (curr){
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        } else{
            curr = temp;
            head = temp;
        }
    }
    DoublyLinkedListNode *temp = head;
    while (temp->next){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while (temp){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}