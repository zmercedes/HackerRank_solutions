#include <limits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> magazineWords;
    
    for(auto word : magazine){
        unordered_map<string, int>::const_iterator look = magazineWords.find(word);
        if(look == magazineWords.end()){
            magazineWords.insert(make_pair(word, 1));
        } else
            magazineWords[word]++;
    }
  
    for(auto word : ransom){
        unordered_map<string, int>::const_iterator look = magazineWords.find(word);
        if(look == magazineWords.end() || magazineWords[word] == 0)
            return false;
        else
            magazineWords[word]--;
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}