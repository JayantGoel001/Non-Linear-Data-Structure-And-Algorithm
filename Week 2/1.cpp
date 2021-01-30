#include<iostream>
#include <map>
using namespace std;

int main(){
    map<pair<int,int>,int> m1;
    cout<<"Enter Row and Column of 1st Sparse Matrix:\n";
    int row1,col1;
    cin>>row1>>col1;

    cout<<"Enter number of entries of 1st Sparse Matrix:\n";
    int n1;
    cin>>n1;
    cout<<"Enter Row, Column, Data:\n";
    for (int i = 0; i < n1; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        m1.insert(make_pair(make_pair(r,c),d));
    }

    map<pair<int,int>,int> m2;
    cout<<"Enter Row and Column of 2nd Sparse Matrix:\n";
    int row2,col2;
    cin>>row2>>col2;

    cout<<"Enter number of entries of 2nd Sparse Matrix:\n";
    int n2;
    cin>>n2;
    cout<<"Enter Row, Column, Data:\n";
    for (int i = 0; i < n2; ++i) {
        int r,c,d;
        cin>>r>>c>>d;
        m2.insert(make_pair(make_pair(r,c),d));
    }
    map<pair<int,int>,int > output;
    if (col1==row2){
        for(auto it=m1.begin();it!=m1.end();it++){
            int r = (it->first).first;
            for(auto it2=m2.begin();it2!=m2.end();it2++){
                int c = (it2->first).second;
                output[make_pair(r,c)] = 0;
            }
        }
        for(auto it=m1.begin();it!=m1.end();it++){
            int r = (it->first).first;
            for(auto it2=m2.begin();it2!=m2.end();it2++){
                int c = (it2->first).second;
                if ((it->first).second == (it2->first).first) {
                    output[make_pair(r, c)] += it->second * it2->second;
                }
            }
        }
        for(auto it=output.begin();it!=output.end();it++){
            if (it->second!=0) {
                cout << (it->first).first << " " << (it->first).second << " " << it->second << "\n";
            }
        }

    } else{
        cout<<"Multiplication Not Possible.\n";
    }
}