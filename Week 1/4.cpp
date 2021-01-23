#include<iostream>
#include <cmath>

using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = nullptr;
    }
    explicit Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
int main(){
    int n;
    cout<<"Enter Number of Elements in List 1:\n";
    cin>>n;
    Node *first = nullptr;
    Node *curr = first;
    cout<<"Enter Elements in List 1:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (curr) {
            curr->next = temp;
            curr = curr->next;
        } else{
            first = temp;
            curr = temp;
        }
    }
    Node *second= nullptr;
    curr = second;
    cout<<"Enter Number of Elements in List 2:\n";
    cin>>n;
    cout<<"Enter Elements in List 2:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        Node *temp = new Node(x);
        if (curr) {
            curr->next = temp;
            curr = curr->next;
        } else{
            curr = temp;
            second = temp;
        }
    }
    int firstNum = 0;
    int secondNum = 0;
    Node *temp1 = first;
    Node *temp2 = second;
    while (temp1!= nullptr){
        firstNum = firstNum * 10 + temp1->data;
        temp1 = temp1->next;
    }
    while (temp2!= nullptr){
        secondNum = secondNum * 10 + temp2->data;
        temp2 = temp2->next;
    }
    int sum = firstNum+secondNum;
    string str = to_string(sum);
    int i = 0;
    int len = str.length();
    Node *output = nullptr;
    Node *current = output;
    while (i<len){
        Node *temp = new Node((int)str[i]-48);
        if (current){
            current->next = temp;
            current = current->next;
        } else{
            current = temp;
            output = temp;
        }
        i++;
    }
    while (output!= nullptr){
        cout<<output->data;
        output = output->next;
        if (output!= nullptr){
            cout<<"->";
        }
    }
}