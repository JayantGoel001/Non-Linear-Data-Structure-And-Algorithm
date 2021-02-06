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
XORLinkedListNode* XOR(DoublyLinkedListNode *a,DoublyLinkedListNode *b){
    return (XORLinkedListNode*)((uintptr_t)(a)^(uintptr_t)(b));
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
    XORLinkedListNode *xorLinkedListHead = nullptr;
    XORLinkedListNode *currXOR = xorLinkedListHead;
    while (temp){
        XORLinkedListNode *tempXOR = new XORLinkedListNode(temp->data);
        tempXOR->npx = XOR(temp->prev,temp->next);
        if (currXOR){

        } else{
            currXOR = tempXOR;
            xorLinkedListHead = tempXOR;
        }

        temp = temp->next;

    }

}