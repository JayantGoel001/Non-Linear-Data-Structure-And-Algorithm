#include<iostream>
using namespace std;

int getSum(int *tree,int i){
    int sum = 0;
    i = i+1;
    while (i>0){
        sum+=tree[i];
        i -= i&-i;
    }
    return sum;
}

void updateBIT(int *tree,int n,int i,int value){
    i = i+1;
    while (i<=n){
        tree[i] +=value;
        i += i&-i;
    }
}

int *constructBITree(int *ar,int n){
    int *tree = new int[n+1];
    for (int i = 0; i <=n; ++i) {
        tree[i] = 0;
    }
    for (int i = 0; i <n; ++i) {
        updateBIT(tree,n,i,ar[i]);
    }
    return tree;
}
int main(){
    cout<<"Enter The value of n:\n";
    int n;
    cin>>n;
    int *ar = new int[n];
    cout<<"Enter the value in array:\n";
    for (int i = 0; i < n; ++i) {
        cin>>ar[i];
    }
    int *tree = constructBITree(ar,n);
    cout<<"Enter the index upto which you want sum:\n";
    int index;
    cin>>index;
    cout<<"Sum of elements from 0 to "<<index<<" is "<<getSum(tree,index)<<"\n";
    cout<<"Enter the key and value to be updated:\n";
    int key;
    int value;
    cin>>key>>value;
    updateBIT(tree,n,key,value-ar[key]);
    cout<<"Sum of elements from 0 to "<<index<<" is "<<getSum(tree,index)<<"\n";
}