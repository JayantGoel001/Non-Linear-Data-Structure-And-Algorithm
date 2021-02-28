#include <iostream>
#include<map>
#include <vector>
#include <string>
#include <fstream>
#include<time.h>
#include "json.hpp"
#include "ConsoleColor.h"

using json = nlohmann::json;
using namespace std;

string path_to_Current_Directory = "C://Users/jgoel/CLionProjects/Non-Linear-Data-Structure-And-Algorithm/Final project/";

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

void displayOutput(vector<string> values){
    int i=1;
    cout<<yellow;
    for (auto it = values.begin(); it != values.end(); it++) {
        cout<<i<<". "<< *it << "\n";
        i++;
    }
}
void getAllRecommendationUtil(Trie *root,string key,vector<string> &v){
    if (root) {
        if (root->isEndOfWord) {
            v.push_back(key);
        }
        for (auto it=root->children.begin();it!=root->children.end();it++) {
            getAllRecommendationUtil(it->second, key + it->first, v);
        }
    }
}
vector<string> getAllRecommendation(Trie *root,string key){
    Trie *temp = root;
    bool found = false;
    for (int i = 0; i < key.length(); ++i) {
        int index = key[i];
        if (!temp->children[index]){
            cout<<"Element Not Found";
            found = true;
            break;
        }
        temp = temp->children[index];
    }
    vector<string> v;
    if (!found) {
        getAllRecommendationUtil(temp, key, v);
    }
    return v;
}
void getWordOfTheDay(Trie *root){
    Trie *temp = root;
    string str = "";
    int i;
    char index='a';
    srand(time(0));
    while (!temp->isEndOfWord){
        int numberOfChildren = temp->children.size();
        i = rand()%numberOfChildren;
        int k = 0;
        for(auto it=temp->children.begin();it!=temp->children.end();it++){
            if(k==i){
                index = it->first;
                break;
            }
            k++;
        }
        str += index;
        temp = temp->children[index];
    }
    cout<<yellow<<"Word Of The Day is : "<<green<<"\""<<str<<"\""<<'\n';
    displayOutput(temp->data);
}
string toLowerCase(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
json readJsonFile(){
    json j;
    ifstream readJSON(path_to_Current_Directory+"data.json");
    j = json::parse(readJSON);
    readJSON.close();
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
    cout<<blue<<"3--->Word Of The Day\n";
    cout<<blue<<"4--->Check Whether A Word Is Prefix of Some String Or Not\n";
    cout<<blue<<"5--->Check History\n";
    cout<<blue<<"6--->Longest Prefix of a Word\n";
    cout<<"\n";
}
void welcomeBanner(){
    drawHash(40);
    cout<<blue<<" WELCOME TO OUR DICTIONARY ";
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
            displayOutput(values);
            ofstream historyFile;
            historyFile.open(path_to_Current_Directory+"History.txt", ios_base::app);
            historyFile << key+"\n";
            historyFile.close();
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
        }
        else if(ch==3){
            getWordOfTheDay(root);
        }
        else if(ch==4){
            cout << "Enter A Word :\n";
            string key;
            cin.ignore();
            getline(cin,key);
            vector<string> v = getAllRecommendation(root,key);
            displayOutput(v);
        }
        else if(ch==5){
            ifstream historyFile;
            string key;
            historyFile.open(path_to_Current_Directory+"History.txt");
            int i=1;
            cout<<"Recently Searched Words:\n";
            while (getline(historyFile,key)){
                cout<<yellow<<i<<". "<<key<<"\n";
                i++;
            }
            historyFile.close();
        }
        else if(ch==6){

        }
        else{
            cout<<red<<"Wrong Input\nTry Again....";
            break;
        }
        char cont;
        cout<<red<<"\n\nDo You Wish To Continue [Y/n]:\n";
        cin>>cont;
        if (cont=='n'||cont=='N'){
            drawHash(40);
            cout<<blue<<" Thank You ";
            drawHash(40);
            break;
        } else{
            welcomeBanner();
        }
        cout<<white;
    }
}