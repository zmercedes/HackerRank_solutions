#include <vector>           // vector
#include <iostream>         // cin, cout
#include <string>           // string, getline
#include <cstdlib>          // stoi, stol

using namespace std;

bool withinMapRange(int i,int j, int r,int c){
    return r >= 0 && r < i && c >= 0 && c < j;
}

void detonate(vector<string>& inverseInit, int i, int j){
    // cout << "point (" << i << "," << j << ")\n";
    for(int r = i-1;r <= i+1;r++){
        for(int c = j-1; c<= j+1;c++){
            if(withinMapRange(inverseInit.size(),inverseInit[0].size(),r,c)){
                if(r == i || c == j){
                    inverseInit[r][c] = '.';
                }
            }
        }
    }
}

vector<string> getConfigAtN(long int n, int r, int c, vector<string>& init){ // 4 cases:
    if(n == 0 || n%4 == 1)  // case 0,1
        return init;
    
    string filler(c,'O');
        
    vector<string> fill(r, filler);
    
    if(n%2 == 0)            // case 2
        return fill;
    
    vector<string> inverseInit = fill;
  
    for(int i = 0;i < r; i++){
        for(int j = 0;j < c;j++){
            if(init[i][j] == 'O')
                detonate(inverseInit, i,j);
        }
    }

    return inverseInit;     // case 3
}

int main() {
    int r,c, counter = 0;
    long int n;
    string input;
    string convert = "";
    
    getline(cin,input);
    
    for(int i = 0;i< input.length();i++){ // parses the input into r,c,n
        if(input[i] == ' '){
            if(counter == 0)
                r = stoi(convert);
            else if(counter == 1)
                c = stoi(convert);
            
            convert = "";
            counter++;
        } 
        if(i+1 == input.length() -1){
            convert+= input[input.length() -1];
            n = stol(convert);
            break;
        }
        
        convert += input[i];
    }
    //cout << r << " " << c << " " << n << endl;
    
    vector<string> init;
    
    for(int i = 0;i < r;i++){
        getline(cin,input);
        init.push_back(input);
    }
    
    init = getConfigAtN(n,r,c,init);
    
    for(int i = 0; i < r;i++){
        for(int j = 0; j < c; j++)
            cout << init[i][j];
        cout << endl;
    }
    
    return 0;
}