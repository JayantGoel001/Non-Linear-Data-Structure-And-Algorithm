#include <iostream>
#include <vector>
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
void getAllRecommendationUtil(Trie *root,string key,vector<string> &v){
    if (root) {
        if (root->isEndOfWord) {
            v.push_back(key);
        }
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                getAllRecommendationUtil(root->children[i], key + ((char) (i + 97)), v);
            }
        }
    }
}
vector<string> getAllRecommendation(Trie *root,string key){
    Trie *temp = root;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i] - 'a';
        if (!temp->children[index]){
            cout<<"Element Not Found";
        }
        temp = temp->children[index];
    }
    vector<string> v;
    getAllRecommendationUtil(temp,key,v);
    return v;
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
    cout<<"Enter the Query :\n";
    cin>>str;
    vector<string> v = getAllRecommendation(root,str);

    cout<<"Recommendation are :\n";
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<"\n";
    }
}