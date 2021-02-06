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
class XORLinkedListNode{
public:
    int data;
    XORLinkedListNode *npx;
    XORLinkedListNode(){
        this->data = 0;
        this->npx = nullptr;
    }
    XORLinkedListNode(int data){
        this->data = data;
        this->npx = nullptr;
    }
};
XORLinkedListNode* XOR(XORLinkedListNode *a,XORLinkedListNode *b){
    return (XORLinkedListNode*)((uintptr_t)(a)^(uintptr_t)(b));
}

void printList(XORLinkedListNode *head){
    if (!head){
        return;
    }
    cout<<"In Forward Direction:\n";
    XORLinkedListNode *temp = head;
    XORLinkedListNode *prev = nullptr;
    while (true){
        cout<<temp->data<<" ";
        XORLinkedListNode *next = XOR(prev,temp->npx);
        prev = temp;
        if (!next){
            break;
        }
        temp = next;
    }
    cout<<"\n\nIn Backward Direction:\n";

    XORLinkedListNode *next = nullptr;
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
    DoublyLinkedListNode *doublyLinkedListHead = nullptr;
    DoublyLinkedListNode *curr = doublyLinkedListHead;
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
            doublyLinkedListHead = temp;
        }
    }
    DoublyLinkedListNode *temp = doublyLinkedListHead;
    while (temp->next){
        temp = temp->next;
    }
    XORLinkedListNode *xorLinkedListHead = nullptr;
    while (temp){
        XORLinkedListNode *tempXOR = new XORLinkedListNode(temp->data);
        tempXOR->npx = xorLinkedListHead;

        if (xorLinkedListHead){
            xorLinkedListHead->npx = XOR(tempXOR,xorLinkedListHead->npx);
        }
        xorLinkedListHead = tempXOR;
        temp = temp->prev;
    }
    printList(xorLinkedListHead);
}