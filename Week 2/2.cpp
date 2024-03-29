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
        temp_row = temp_row->right;
    }
    Node *temp_col = head_col;
    for (int i = 0; i < col - 1; ++i) {
        temp_col->down = new Node(i+1);
        temp_col = temp_col->down;
    }

    cout<<"Enter number of entries to be inserted:\n";
    int n;
    cin>>n;
    cout<<"Enter Row,Column,Data:\n";
    for (int i = 0; i < n; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        Node *tempRow = head_row;

        while (tempRow){
            if (tempRow->value == r){
                break;
            }
            tempRow = tempRow->right;
        }

        Node *tempCol = head_col;
        while (tempCol){
            if (tempCol->value==c){
                break;
            }
            tempCol = tempCol->down;
        }


        Node *temp = new Node(r,c,d);
        if (tempRow->down){
            Node *tempRowCol = tempRow;
            while (tempRowCol->down!=tempRow){
                if (tempRowCol->down->col < c){
                    tempRowCol = tempRowCol->down;
                } else{
                    break;
                }
            }
            Node *next_node_col = tempRowCol->down;
            tempRowCol->down = temp;
            temp->down = next_node_col;
        } else{
            tempRow->down = temp;
            temp->down = tempRow;
        }

        if (tempCol->right){
            Node *tempColRow = tempCol;
            while (tempColRow->right!=tempCol){
                if (tempColRow->right->row < r){
                    tempColRow = tempColRow->right;
                } else{
                    break;
                }
            }
            Node *next_node_row = tempColRow->right;
            tempColRow->right = temp;
            temp->right = next_node_row;
        } else{
            tempCol->right = temp;
            temp->right = tempCol;
        }
    }

    cout<<"Sparse Matrix LinkedList Representation:\n\n";
    cout<<"Row Wise:\n";
    Node *temp0 = head;
    for (int i = 0; i < row; ++i) {
        temp0 = temp0->right;
        Node *temp1 = temp0;
        cout<<temp1->value<<"-->";
        temp1 = temp1->down;
        while (temp1 && temp1!=temp0){
            cout<<temp1->value<<" ";
            temp1 = temp1->down;
        }
        cout<<"\n";
    }
    cout<<"\nColumn Wise:\n";
    temp0 = head;
    for (int i = 0; i < col; ++i) {
        temp0 = temp0->down;
        Node *temp1 = temp0;
        cout<<temp1->value<<"-->";
        temp1 = temp1->right;
        while (temp1 && temp1!=temp0){
            cout<<temp1->value<<" ";
            temp1 = temp1->right;
        }
        cout<<"\n";
    }
}

//Output:
//
//(1).
//Enter the number of rows and columns:
//6 5
//Enter number of entries to be inserted:
//6
//Enter Row,Column,Data:
//0 2 2
//1 1 11
//2 4 24
//3 2 32
//4 0 40
//5 3 53
//Sparse Matrix LinkedList Representation:
//
//Row Wise:
//0-->2
//1-->11
//2-->24
//3-->32
//4-->40
//5-->53
//
//Column Wise:
//0-->40
//1-->11
//2-->2 32
//3-->53
//4-->24


//(2).
//Enter the number of rows and columns:
//5 6
//Enter number of entries to be inserted:
//6
//Enter Row,Column,Data:
//2 0 20
//1 1 11
//2 3 23
//4 2 42
//0 4 4
//3 5 35
//Sparse Matrix LinkedList Representation:
//
//Row Wise:
//0-->4
//1-->11
//2-->20 23
//3-->35
//4-->42
//
//Column Wise:
//0-->20
//1-->11
//2-->42
//3-->23
//4-->4
//5-->35
