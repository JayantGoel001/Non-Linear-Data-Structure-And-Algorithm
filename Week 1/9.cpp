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
    Node *prev = nullptr;
    while (temp) {
        int x = temp->data;
        if (m.count(x) == 0) {
            m[x] = 1;
            prev = temp;
        } else {
            if (prev){
                prev->next = temp->next;
            }
        }
        temp = temp->next;
    }
    while (head!= nullptr){
        cout<<head->data;
        if (head->next){
            cout<<"-->";
        }
        head=head->next;
    }
}