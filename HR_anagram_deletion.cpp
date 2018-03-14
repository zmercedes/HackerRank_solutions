// Zoilo Mercedes
// Hackerrank problem: making anagrams
// give minimum number of deletions to make two strings anagrams

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

int number_needed(string a, string b) {
    int count = 0;
    vector<int> freq(26,0);

    // the following keep track of strings 
    for(auto c: a){ ++freq[c-'a']; } 
    for(auto c: b){ --freq[c-'a']; }
    for(auto val: freq){ count+= abs(val); }
    
    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
