#include <iostream>
using namespace std;
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
    cout<<"Enter M And N :\n";
    int M,N;
    cin>>M>>N;
    Node *temp = head;
    Node *output = nullptr;
    Node *ptr = output;
    while (temp!= nullptr) {
        int i = 0;
        while (i < M && temp != nullptr) {
            Node *dataPtr = new Node(temp->data);
            if (ptr) {
                ptr->next = dataPtr;
                ptr = ptr->next;
            } else {
                ptr = dataPtr;
                output = dataPtr;
            }
            temp = temp->next;
            i++;
        }
        int j = 0;
        while (j < N && temp != nullptr) {
            temp = temp->next;
            j++;
        }
    }
    Node *printOutput = output;
    while (printOutput){
        cout<<printOutput->data<<" ";
        printOutput = printOutput->next;
    }
}