#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map> 

using namespace std;

class Trie{
    public:
        Trie(): root{new tNode} { }
        
        void addName(string name){
            tNode* tmp = root;
            unordered_map<char,tNode*>::const_iterator look = tmp->children.find(name[0]);
            if(look == tmp->children.end()){
                for(auto i = 0;i<name.length();++i){
                    tmp->children[name[i]] = new tNode;
                    tmp = tmp->children[name[i]];
                }
            } else {
                tmp = tmp->children[name[0]];
                for(auto i = 1;i<name.length();++i){
                    look = tmp->children.find(name[i]);
                    if(look == tmp->children.end())
                        tmp->children[name[i]] = new tNode;
                        
                    tmp = tmp->children[name[i]];
                }   
            }
            tmp->isComplete = true;
        }
    
        void findPartial(string name){
            cout << "FIND CALLED with \"" << name << "\"\n";
            tNode* tmp = root;
            unordered_map<char,tNode*>::const_iterator look; 
            for(auto i = 0;i<=name.length();++i){
                cout << name[i] << endl;
                look = tmp->children.find(name[i]);
                if(look == tmp->children.end()){
                    cout << name[i] << 0 << endl;
                    break;
                } else
                    tmp = tmp->children[name[i]];
            }
            cout << tmp->children.size() << "for \"" << name << "\"\n";
        }
    
    private:
        struct tNode{
            unordered_map<char, tNode*> children;
            bool isComplete = false;
        };
        tNode* root;
};

int main(){
    int n;
    cin >> n;
    Trie t;
    for(int a0 = 0; a0 < n; ++a0){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add")
            t.addName(contact);
        else if(op == "find")
            t.findPartial(contact);
    }
    return 0;
}