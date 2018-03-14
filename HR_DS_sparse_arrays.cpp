#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; // number of strings to input
    cin >> n;
    unordered_map<string,int> strings;
    for(int i = 0;i<n;i++){
        string input;
        cin >> input;
        unordered_map<string,int>::const_iterator look = strings.find(input);
        if(look == strings.end())
            strings.insert({input,1});
        else
            strings[input]++;
    }
    
    int q; // queries
    cin >> q;
    for(int i=0;i<q;i++){
        string input;
        cin >> input;
        unordered_map<string,int>::const_iterator look = strings.find(input);
        if(look == strings.end())
            cout << 0 << endl;
        else
            cout << strings[input] << endl;
    }
    return 0;
}