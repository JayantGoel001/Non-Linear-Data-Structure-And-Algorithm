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

void remove(Trie *root,string key){
    Trie *temp = root;

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
    cout<<(search(root,str)?"Word Exists":"Word Does Not Exists");

}