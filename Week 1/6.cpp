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
bool detectAndRemoveLoop(Node *head){
    map<int,bool> isVisited;
    while (head!= nullptr){
        if (isVisited.count(head->data)==0) {
            isVisited[head->data] = true;
        } else{
            return true;
        }
        head=head->next;
    }
    return false;
}
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
    bool hasLoop = detectAndRemoveLoop(head);
    if (hasLoop){
        cout<<"It Contains Loop\n";
    } else{
        cout<<"It does not contain Loop\n";
    }
}