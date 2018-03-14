/*
 * Zoilo Mercedes
 * Hacker Rank Implementation: Kangaroo
 * Two kangaroos start in certain position (x1, x2)
 * Move at different velocities (v1, v2)
 */
#include <iostream>

using namespace std;

int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    while(true){
        // if one of the kangs is further ahead and moves faster
        if(x1 > x2 && v1 > v2 || x1 < x2 && v1 < v2 || 
        // or if one of the kangs is ahead and both move at the same speed
           x1 > x2 && v1 == v2 || x1 < x2 && v1 == v2){
            cout << "NO" << endl;
            return 0;
        }
        x1 += v1;
        x2 += v2;
        if(x1 == x2){
            cout << "YES" << endl;
            return 0;
        }
    }
    
    return 0;
}
