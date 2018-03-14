#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long int n, max = 0, sum = 0;
    int m;
    cin >> n >> m;
    
    vector<long int> numberList(n,0);
    
    for(int i = 0;i<m;i++){
        long int a,b,k;
        cin >> a >> b >> k;
        numberList[a-1] += k;
        numberList[b] -= k; 
    }
    for(int j = 0; j<n;j++){
        sum += numberList[j];
        if(sum > max)
            max = sum;
    }
    
    cout << max;
    return 0;
}
