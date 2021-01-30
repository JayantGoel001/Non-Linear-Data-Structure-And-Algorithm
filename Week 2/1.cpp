#include<iostream>
#include <list>
#include <map>
using namespace std;

class Sparse{
public:
    int row;
    int col;
    int data;
    Sparse(){
        row=0;
        col=0;
        data=0;
    }
    Sparse(int row,int col,int data){
        this->row = row;
        this->col = col;
        this->data = data;
    }
};

int main(){
    list<Sparse> l1;
    cout<<"Enter Row and Column of 1st Sparse Matrix:\n";
    int row1,col1;
    cin>>row1>>col1;

    cout<<"Enter number of entries of 1st Sparse Matrix:\n";
    int n1;
    cin>>n1;
    for (int i = 0; i < n1; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        Sparse sparse(r,c,d);
        l1.push_back(sparse);
    }

    list<Sparse> l2;
    cout<<"Enter Row and Column of 1st Sparse Matrix:\n";
    int row2,col2;
    cin>>row2>>col2;

    cout<<"Enter number of entries of 1st Sparse Matrix:\n";
    int n2;
    cin>>n2;
    for (int i = 0; i < n2; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        Sparse sparse(r,c,d);
        l2.push_back(sparse);
    }
    if (col1==row2){
        map<int,map<int,int>> m1;
        for(auto it=l1.begin();it!=l1.end();it++){
            if(m1.count(it->row)==0){
                m1[it->row] =
            }
        }
    } else{
        cout<<"Multiplication Not Possible.\n";
    }
}