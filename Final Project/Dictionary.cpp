#include <iostream>
#include<map>
#include <vector>
#include <string>
using namespace std;

class Trie{
public:
    map<char,Trie*> children;
    bool isEndOfWord;
    vector<string> data;
    Trie(){
        this->isEndOfWord = false;
    }
};

void insert(Trie *root,string key,vector<string> data){
    Trie *temp = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i];
        if (!temp->children[index]){
            temp->children[index] = new Trie();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
    temp->data = data;
}

vector<string> search(Trie *root,string key){
    vector<string> notFound;
    notFound.push_back("Word Not Found");
    Trie *temp = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i];
        if (!temp->children[index]){
            return notFound;
        }
        temp = temp->children[index];
    }
    if(temp!= nullptr && temp->isEndOfWord){
        return temp->data;
    } else{
        return notFound;
    }
}
void removeUtil(Trie *root,string key,int i){
    if (i!=key.length()){
        int index = key[i];
        removeUtil(root->children[index],key,i+1);
        delete root;
    }
}

void remove(Trie *root,string key){
    Trie *temp = root;
    Trie *lastEndOfWord = root;
    int lastEndOfWordIndex = 0;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] ;
        if (!temp->children[index]){
            cout<<"Element Not Found";
        }
        if (i!=key.length()-1 && temp->isEndOfWord){
            lastEndOfWord = temp;
            lastEndOfWordIndex = i;
        }
        temp = temp->children[index];
    }
    removeUtil(lastEndOfWord,key,lastEndOfWordIndex);
}

int main(){
    cout<<"Enter Number of Words :\n";
    int n;
    cin>>n;

    string str;
    Trie *root = new Trie();
    for (int i = 0; i < n; ++i) {
        cin>>str;
        vector<string> values;
        insert(root,str,values);
    }

    cout<<"Enter Word To Be Searched :\n";
    cin>>str;
    vector<string> values = search(root,str);
    for(auto it=values.begin();it!=values.end();it++) {
        cout << *it << "\n";
    }

    cout<<"Enter Word To Be Deleted :\n";
    cin>>str;
    remove(root,str);
}