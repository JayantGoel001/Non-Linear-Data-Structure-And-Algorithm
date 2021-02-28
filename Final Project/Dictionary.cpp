#include <iostream>
#include<map>
#include <vector>
#include <string>
#include <fstream>
#include "json.hpp"
#include "ConsoleColor.h"

using json = nlohmann::json;
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
        char index = key[i];
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
        char index = key[i];
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
Trie* removeUtil(Trie *root,string key,int i,bool &found){
    if (!root){
        return nullptr;
    }
    if (i == key.length()){
        if (root->isEndOfWord){
            root->isEndOfWord = false;
            found = true;
        }
        if (root->children.size()==0){
            delete root;
            root = nullptr;
        }
        return root;
    }
    char index = key[i];
    root->children[index] = removeUtil(root->children[index],key,i+1,found);
    if(root->children.size()==0 && !root->isEndOfWord){
        delete root;
        root = nullptr;
    }
    return root;
}
bool remove(Trie *root,string key){
    bool found = false;
    removeUtil(root,key,0,found);
    return found;
}
string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
json readJsonFile(){
    json j;

    ifstream readJSON("C://Users/jgoel/CLionProjects/Non-Linear-Data-Structure-And-Algorithm/Final project/data.json");
    j = json::parse(readJSON);
    return j;
}
void drawHash(int n){
    for (int i = 0; i < n; ++i) {
        cout<<white<<"#";
    }
}
void displayChoice(){
    cout<<"\n\n";
    cout<<red<<"Type....\n";

    cout<<blue<<"1--->Search A Word\n";
    cout<<blue<<"2--->Delete A Word\n";
    cout<<"\n";
}
void welcomeBanner(){
    drawHash(40);
    cout<<white<<" WELCOME TO OUR DICTIONARY ";
    drawHash(40);
}
int main(){
    json j = readJsonFile();

    Trie *root = new Trie();
    for(auto it=j.begin();it!=j.end();it++){
        string key = it.key();
        insert(root,toLowerCase(key),*it);
    }
    welcomeBanner();
    while (true){
        displayChoice();
        cout<<green;
        int ch;
        cin>>ch;
        if(ch==1) {
            cout << "Enter Word To Be Searched :\n";
            string key;

            cin.ignore();
            getline(cin,key);

            vector<string> values = search(root, toLowerCase(key));
            cout<<"\n";
            int i=1;
            cout<<yellow;
            for (auto it = values.begin(); it != values.end(); it++) {
                cout<<i<<". "<< *it << "\n";
                i++;
            }
        }
        else if(ch==2){
            cout<<"Enter Word To Be Deleted :\n";
            string key;

            cin.ignore();
            getline(cin,key);

            if(remove(root,toLowerCase(key))){
                cout<<yellow<<key<<" removed Successfully.";
            } else{
                cout<<red<<"Element Not Found";
            }
        } else{
            cout<<red<<"Wrong Input\n";
            break;
        }
        char cont;
        cout<<red<<"\n\nDo You Wish To Continue [Y/n]:\n";
        cin>>cont;
        if (cont=='n'||cont=='N'){
            break;
        } else{
            welcomeBanner();
        }
        cout<<white;
    }
}