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
    void HeaderNode(int v){
        this->value = v;
        down = nullptr;
        right = nullptr;
    }
    void ElementNode(int r,int c,int v){
        this->row = r;
        this->col = c;
        this->value = v;
        down = nullptr;
        right = nullptr;
    }
};
int main(){
    vector<Node> head;

}