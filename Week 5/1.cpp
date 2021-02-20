#include <iostream>
using namespace std;

class Trie{
public:
    Trie **children;
    bool isEndOfWord;
    Trie(){
        children = new Trie*[26];
        this->isEndOfWord = false;

        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

void insert(Trie *root,string key){
    Trie *temp = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if (!temp->children[index]){
            temp->children[index] = new Trie();
        }
        temp = temp->children[index];
    }
    temp->isEndOfWord = true;
}

bool search(Trie *root,string key){
    Trie *temp = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if (!temp->children[index]){
            return false;
        }
        temp = temp->children[index];
    }
    return temp!= nullptr && temp->isEndOfWord;
}
void removeUtil(Trie *root,string key,int i){
    if (i!=key.length()){
        int index = key[i] - 'a';
        removeUtil(root->children[index],key,i+1);
        delete root;
    }
}

void remove(Trie *root,string key){
    Trie *temp = root;
    Trie *lastEndOfWord = root;
    int lastEndOfWordIndex = 0;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
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
        insert(root,str);
    }

    cout<<"Enter Word To Be Searched :\n";
    cin>>str;
    cout<<(search(root,str)?"Word Exists":"Word Does Not Exists")<<"\n";

    cout<<"Enter Word To Be Deleted :\n";
    cin>>str;
    remove(root,str);
}