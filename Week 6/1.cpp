#include <iostream>
#include <map>
using namespace std;
class SuffixTree{
public:
    map<string ,SuffixTree*> children;
    SuffixTree(){
        this->children[""] = nullptr;
    }
};
SuffixTree* insert(SuffixTree *tree,string str){
    if (!tree){
        tree = new SuffixTree();
        tree->children[str] = new SuffixTree();
    } else{
        SuffixTree *parent = nullptr;
        SuffixTree *temp = tree;
        int i=0;
        while (true) {
            string index = to_string(str[i]);
            if (temp->children.count(index) != 0) {
                parent = temp;
                temp = temp->children[index];
                i++;
            } else{
                break;
            }
        }
        map<string, SuffixTree *> mp = parent->children;
        bool containCommon = false;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first[i] == str[i]) {
                containCommon = true;
                string key = it->first;
                parent->children.erase(key);
                int k = i;
                while (key[k] == str[k] && k < min(key.size(), str.size())) {
                    k++;
                }
                parent->children[key.substr(i, k)] = new SuffixTree();
                temp = parent->children[key.substr(i, k)];
                temp->children[key.substr(k)] = new SuffixTree();
                temp->children[str.substr(k)] = new SuffixTree();
                break;
            }
        }
        if (!containCommon) {
            parent->children[str] = new SuffixTree();
            temp = parent->children[str];
        }
    }
    return tree;
}
void printTree(SuffixTree *tree){
    if (tree) {
        for (auto it = tree->children.begin(); it != tree->children.end(); it++) {
            cout << it->first << "\n";
            printTree(tree->children[it->first]);
        }
    }
}
int main(){
    string words[8] = {"bear","bell","bid","bull","buy","sell","stock","stop"};
    SuffixTree *tree = new SuffixTree();
    for (int i = 0; i < words->size(); ++i) {
        tree = insert(tree,words[i]);
    }
    cout<<"Successfully Created Suffix Tree\n";
    printTree(tree);
}