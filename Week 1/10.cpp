#include <iostream>
#include <map>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
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
    map<int,int> m;
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
    int count = 0;
    int k;
    cout<<"Enter The value to be searched:\n";
    cin>>k;
    while (temp) {
        int x = temp->data;
        if (x==k){
            count++;
        }
        temp = temp->next;
    }
    cout<<count<<"\n";
}