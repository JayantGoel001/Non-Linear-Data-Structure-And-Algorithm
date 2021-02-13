#include <iostream>
#include <cmath>

using namespace std;
class Node{
public:
    const int SIZE = 4;
    int count;
    int *arr;
    Node *next;
    Node(){
        this->count = 0;
        this->arr = new int[this->SIZE];
        this->next = nullptr;
    }
};
Node* Insert(Node *head,int data){
    Node *curr = head;
    if (curr){
        while (curr->next){
            if (curr->next->arr[0]>data){
                break;
            }
            curr = curr->next;
        }

        if (curr->count == curr->SIZE){
            Node *temp = curr->next;
            curr->next = new Node();
            int *arr = curr->arr;

            int minRange = ceil((float )curr->SIZE / 2);
            int maxRange = curr->SIZE;
            for (int j = minRange; j <maxRange ; ++j) {
                curr->next->arr[curr->next->count] = arr[j];
                curr->count = curr->count-1;
                arr[j] = -1;
                curr->next->count = curr->next->count + 1;
            }
            curr->next->next = temp;
        }

        if (curr->next && curr->next->arr[0] <data){
            curr = curr->next;
        }
        for (int i = 0; i < curr->count; ++i) {
            if (curr->arr[i]>data){
                int temp = curr->arr[i];
                curr->arr[i] = data;
                data = temp;
            }
        }
        curr->arr[curr->count] = data;
        curr->count = curr->count + 1;
    } else{
        curr = new Node();
        curr->arr[0] = data;
        curr->count = curr->count+1;
        head = curr;
    }
    return head;
}
void Delete(Node *head,int data){
    Node *curr = head;
    Node *prev = nullptr;
    while (curr->next){
        if (curr->next->arr[0]>data){
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    int k = 0;
    for (int i = 0; i < curr->count; ++i) {
        if (curr->arr[i]==data){
            continue;
        }
        curr->arr[k] = curr->arr[i];
        k++;
    }
    curr->count = curr->count - 1;
    if (curr->count==0){
        prev->next = curr->next;
    }
}
pair<int,int> Search(Node *head,int data){
    int k = 0;
    int pos = -1;
    while (head->next){
        if (head->next->arr[0]>data){
            break;
        }
        head = head->next;
        k++;
    }
    for (int i = 0; i < head->count; ++i) {
        if (head->arr[i]==data){
            pos = i;
            break;
        }
    }
    return make_pair(k+1,pos+1);
}
void printList(Node *head){
    Node *temp = head;
    while (temp){
        for (int i = 0; i < temp->count; ++i) {
            cout<<temp->arr[i]<<" ";
        }
        cout<<"\n";
        temp = temp->next;
    }
}
int main(){
    int n;
    cout<<"Enter number of elements:\n";
    cin>>n;
    Node *head = nullptr;
    for (int i = 0; i < n; ++i) {
        int data;
        cin>>data;
        head = Insert(head,data);
    }
    printList(head);

    cout<<"\nEnter Number to be deleted:\n";
    int delEle;
    cin>>delEle;
    Delete(head,delEle);
    printList(head);

    cout<<"Enter Number to be searched:\n";
    int searchEle;
    cin>>searchEle;
    pair<int,int> p = Search(head,searchEle);
    cout<<"Element is found in List Number "<<p.first<<" at "<<p.second<<" ";
}