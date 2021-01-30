#include <iostream>
#include <queue>

using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *child;
    Node(){
        this->data = 0;
        this->next = nullptr;
        this->child = nullptr;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
    }
};
int main(){
    Node *head = new Node(10);
    Node *temp = head;

    temp->next = new Node(5);
    temp->child = new Node(4);
    temp = temp->next;
    temp->next = new Node(12);
    temp = temp->next;
    temp->next = new Node(7);
    temp = temp->next;

    temp->next = new Node(11);
    temp->child = new Node(17);
    temp = temp->child;
    temp->next = new Node(6);
    temp->child = new Node(9);
    temp = temp->child;
    temp->next = new Node(8);
    temp->child = new Node(19);
    temp = temp->child;
    temp->next = new Node(15);

    temp = head->child;
    temp->next = new Node(20);
    temp = temp->next;
    temp->next = new Node(13);
    temp->child = new Node(2);
    temp = temp->next;
    temp->child = new Node(16);
    temp = temp->child;
    temp->child = new Node(3);

    temp = head;
    queue<Node *> q;
    while (!q.empty() || temp){
        cout<<temp->data<<"->";
        if (temp->child){
            q.push(temp->child);
        }
        temp = temp->next;
        if (!temp){
            if (!q.empty()) {
                temp = q.front();
                q.pop();
            } else{
                break;
            }
        }
    }
}