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
        maxEle = INT32_MIN;
        minEle = INT32_MAX;
    }
    Node(int data,int index){
        interval = make_pair(index,index);
        sum = data;
        maxEle = data;
        minEle = data;
        left = nullptr;
        right = nullptr;
    }
    Node(int *ar,int start,int end){
        interval = make_pair(start,end);
        sum = ar[0];
        minEle = ar[1];
        maxEle = ar[2];
        left = nullptr;
        right = nullptr;
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

int *constructSegmentTreeUtil(int *ar,int start,int end,Node* root,int si){
    if (start==end){
        root = new Node(ar[start],start);
        return createSumMinMaxArray(root);
    }
    int mid = getMid(start,end);
    root->left = new Node();
    root->right = new Node();
    int *left = constructSegmentTreeUtil(ar,start,mid,root->left,2*si+1);
    int *right = constructSegmentTreeUtil(ar,mid+1,end,root->right,2*si+2);
    int *sumMinMax = new int[3];
    sumMinMax[0] = left[0]+right[0];
    sumMinMax[1] = (left[1]>right[1])?right[1]:left[1];
    sumMinMax[2] = (left[2]<right[2])?right[2]:left[2];
    root = new Node(sumMinMax,2*si+1,2*si+2);
    return sumMinMax;
}

Node* constructSegmentTree(int *ar,int n){
    Node *root = new Node();
    constructSegmentTreeUtil(ar,0,n-1,root,0);
    return root;
}
int main(){
    int ar[] = {1,4,6,8,10,12,15};
    int n = 7;
    Node *segmentTree = constructSegmentTree(ar,n);
    int *values = getSumMinMax(segmentTree,2,4);
    cout<<values[0]<<"\n";
    cout<<values[1]<<"\n";
    cout<<values[2]<<"\n";
}