#include <iostream>
#include <vector>

using namespace std;
class Node{
public:
    int value;
    int row;
    int col;
    Node *down;
    Node *right;
    //Header Node for each row and column
    Node(int v){
        this->value = v;
        this->down = nullptr;
        this->right = nullptr;
    }
    //Head Node
    Node(int r,int c){
        this->row = r;
        this->col = c;
        this->down = nullptr;
        this->right = nullptr;
    }
    //Element Node
    Node(int r,int c,int v){
        this->row = r;
        this->col = c;
        this->value = v;
        this->down = nullptr;
        this->right = nullptr;
    }
};
int main(){

    int row,col;
    cout<<"Enter the number of rows and columns:\n";
    cin>>row>>col;


    Node *head_row = new Node(0);
    Node *head_col = new Node(0);

    Node *head = new Node(row,col);
    head->right = head_row;
    head->down = head_col;


    Node *temp_row = head_row;
    for (int i = 0; i < row - 1; ++i) {
        temp_row->right = new Node(i+1);
    }
    Node *temp_col = head_col;
    for (int i = 0; i < col - 1; ++i) {
        temp_col->down = new Node(i+1);
    }
    cout<<"Enter number of entries to be inserted:\n";
    int n;
    cin>>n;
    cout<<"Enter Row,Column,Data:\n";
    for (int i = 0; i < n; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        Node *tempRow = head_row;
        while (tempRow != nullptr){
            if (tempRow->value == r){
                break;
            }
            tempRow = tempRow->right;
        }

        Node *tempCol = head_col;
        while (tempCol!= nullptr){
            if (tempCol->value==c){
                break;
            }
            tempCol = tempCol->down;
        }

        Node *temp = new Node(r,c,d);
        if (!tempRow->down){
            Node *tempRowCol = tempRow;

        } else{
            tempRow->down = temp;
            temp->down = tempRow;
        }

        if (!tempCol->right){

        } else{
            tempCol->right = temp;
            temp->right = tempCol;
        }
    }
}