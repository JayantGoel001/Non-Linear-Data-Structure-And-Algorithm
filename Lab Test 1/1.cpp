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
void BFS(Node *head,int row,int col){
    bool isVisited[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            isVisited[i][j] = false;
        }
    }
    vector<int> q;
    q.push_back(head->right->down->value);
    int visited;
    while (!q.empty()){
        visited = q[0];
        cout<<visited<<" ";
        q.erase(q.begin());
        if (head->right && head->right->value!=-1){
            q.push_back(head->right->value);
            head = head->right;
        }
        if (head->down && head->down->value!=-1){
            q.push_back(head->down->value);
            head = head->down;
        }
    }
}
int main(){

    int row,col;
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
    for(int c=0; c < row; c++)
    {
        for (int r = 0; r < col; ++r) {
            int d;
            cin>>d;
            if (d!=-1){
                Node *tempRow = head_row;

                while (tempRow){
                    if (tempRow->value == c){
                        break;
                    }
                    tempRow = tempRow->right;
                }

                Node *tempCol = head_col;
                while (tempCol){
                    if (tempCol->value == r){
                        break;
                    }
                    tempCol = tempCol->down;
                }


                Node *temp = new Node(c, r, d);
                if (tempRow->down){
                    Node *tempRowCol = tempRow;
                    while (tempRowCol->down!=tempRow){
                        if (tempRowCol->down->col < r){
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
                        if (tempColRow->right->row < c){
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
        }
    }
    bool *isVisited = new bool[col];
    for (int i = 0; i < col; ++i) {
        isVisited[i] = false;
    }
    BFS(head,row,col);
}