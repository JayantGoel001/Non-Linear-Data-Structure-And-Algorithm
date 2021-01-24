#include <iostream>
#include <map>
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
    Node *output = nullptr;
    Node *cur = output;
    Node *evenPtr = head;
    while (evenPtr!= nullptr){
        if (evenPtr->data%2==0){
            Node *temp = new Node(evenPtr->data);
            if (cur){
                cur->next = temp;
                cur = cur->next;
            } else{
                cur = temp;
                output = temp;
            }
        }
        evenPtr=evenPtr->next;
    }
    Node *oddPtr = head;
    while (oddPtr!= nullptr){
        if (oddPtr->data%2!=0){
            Node *temp = new Node(oddPtr->data);
            if (cur){
                cur->next = temp;
                cur = cur->next;
            } else{
                cur = temp;
                output = temp;
            }
        }
        oddPtr=oddPtr->next;
    }

    Node *printOutput = output;
    while (printOutput){
        cout<<printOutput->data<<" ";
        printOutput = printOutput->next;
    }

    //Another Approach

    Node *temp = head;
    Node *tail = head;
    while (temp!= nullptr && temp->next!= nullptr){
        temp = temp->next;
    }
    tail = temp;
    Node *end = tail;
    temp = head;
    Node *prev = nullptr;
    while (temp!= nullptr && end!= nullptr && temp!=end->next){
        if (temp->data%2!=0){
            Node *secTemp = temp->next;
            if (prev){
                prev->next = secTemp;
            } else{
                head = secTemp;
            }
            if (tail) {
                tail->next = new Node(temp->data);
                tail = tail->next;
            }
        } else {
            prev = temp;
        }
        temp = temp->next;
    }
    cout<<"\n\n";
    while (head){
        cout<<head->data;
        if (head->next){
            cout<<"-->";
        }
        head = head->next;
    }
}