#include <iostream>
using namespace std;

class Node{
public:
    Node *left;
    Node *right;
    pair<int,int> interval;
    int sum;
    int maxEle;
    int minEle;
    Node(){
        interval = make_pair(0,0);
        left = nullptr;
        right = nullptr;
        sum = 0;
        minEle = INT32_MAX;
        maxEle = INT32_MIN;
    }
};

int getMid(int start,int end){
    return (start+end)/2;
}
int *createSumMinMaxArray(Node *root){
    int *sumMinMax = new int[3];
    sumMinMax[0] = root->sum;
    sumMinMax[1] = root->minEle;
    sumMinMax[2] = root->maxEle;
    return sumMinMax;
}
int *getSumMinMaxUtil(Node *root,int qs,int qe){
    if (!root){
        return nullptr;
    }
    if (qs<=root->interval.first && qe>=root->interval.second){
        return createSumMinMaxArray(root);
    }
    if (root->interval.second<qs || root->interval.first>qe){
        int *ar = new int[3];
        ar[0] = 0;
        ar[1] = INT32_MAX;
        ar[2] = INT32_MIN;
        return ar;
    }
    int *left = getSumMinMaxUtil(root->left,qs,qe);
    int *right = getSumMinMaxUtil(root->right,qs,qe);
    int *sumMinMax = new int[3];
    sumMinMax[0] = left[0]+right[0];
    sumMinMax[1] = (left[1]>right[1])?right[1]:left[1];
    sumMinMax[2] = (left[2]<right[2])?right[2]:left[2];
    return sumMinMax;
}

int *getSumMinMax(Node *root,int qs,int qe){
    if (qs<0 || qs>qe){
        cout<<"Invalid Input";
        return nullptr;
    }
    return getSumMinMaxUtil(root,qs,qe);
}

int *constructSegmentTreeUtil(int *ar,int start,int end,Node* root){
    if (start==end){
        root->interval =make_pair(start,end);
        root->sum = ar[start];
        root->minEle = ar[start];
        root->maxEle = ar[start];
        return createSumMinMaxArray(root);
    }
    int mid = getMid(start,end);
    root->left = new Node();
    root->right = new Node();
    int *left = constructSegmentTreeUtil(ar,start,mid,root->left);
    int *right = constructSegmentTreeUtil(ar,mid+1,end,root->right);
    int *sumMinMax = new int[3];
    sumMinMax[0] = left[0]+right[0];
    sumMinMax[1] = (left[1]>right[1])?right[1]:left[1];
    sumMinMax[2] = (left[2]<right[2])?right[2]:left[2];
    root->interval = make_pair(start,end);
    root->sum = sumMinMax[0];
    root->minEle = sumMinMax[1];
    root->maxEle = sumMinMax[2];
    return sumMinMax;
}

Node* constructSegmentTree(int *ar,int n){
    Node *root = new Node();
    constructSegmentTreeUtil(ar,0,n-1,root);
    return root;
}
void updateSegmentTreeUtil(Node *root,int index,int diff){
    if (root->interval.first>index || root->interval.second<index){
        return;
    }
    root->sum +=diff;
    if (root->interval.first!=root->interval.second){
        updateSegmentTreeUtil(root->left,index,diff);
        updateSegmentTreeUtil(root->right,index,diff);
    }
}
void updateSegmentTree(Node *root,int index,int value,int *ar,int n){
    if (index<0 && index>n-1){
        cout<<"Wrong Input\n";
        return;
    }
    int diff = value-ar[index];
    ar[index] = value;
    updateSegmentTreeUtil(root,index,diff);
}
int main(){
    int ar[] = {1,4,6,8,10,12,15};
    int n = 7;
    int qs= 1;
    int qe = 4;
    Node *segmentTree = constructSegmentTree(ar,n);
    int *values = getSumMinMax(segmentTree,qs,qe);
    cout<<"SUM : "<<values[0]<<"\n";
    cout<<"MINIMUM : "<<values[1]<<"\n";
    cout<<"MAXIMUM : "<<values[2]<<"\n";

    int updateIndex = 2;
    int updateValue = 7;
    updateSegmentTree(segmentTree,updateIndex,updateValue,ar,n);
    values = getSumMinMaxUtil(segmentTree,qs,qe);
    cout<<"SUM : "<<values[0]<<"\n";
    cout<<"MINIMUM : "<<values[1]<<"\n";
    cout<<"MAXIMUM : "<<values[2]<<"\n";
}