#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Heap{
    public:
        Heap(bool which, int size): minOrMax{which} {
            h.resize(size);
        }
    
        ~Heap(){
           clear();
        }
    
        void insert(int number){
            h.push_back(number);
            bubbleUp(h.size() - 1);
        }
    
        void bubbleUp(int index){
            if(h.size() == 1)
                return;
            
            int i = index;
            
            while(true){
                if(minOrMax){
                    if(h[i] < h[(i-1)/2]){
                        int temp = h[i];
                        h[i] = h[(i-1)/2];
                        h[(i-1)/2] = temp;
                        i = (i-1)/2;
                    } else if(h[i] == h[(i-1)/2] || i == 0) {
                        break;
                    }
                } else {
                    if(h[i] > h[(i-1)/2]){
                        int temp = h[i];
                        h[i] = h[(i-1)/2];
                        h[(i-1)/2] = temp;
                        i = (i-1)/2;
                    } else if(h[i] == h[(i-1)/2] || i == 0){
                        break;
                    }
                }
            }
        }
    
        void clear() { h.clear(); }
    
        int getRoot() { return h[0]; }
        
    private:
        vector<int> h;
        bool minOrMax; // on true it's a min heap, otherwise max
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    Heap min(true,(n/2)+1);
    Heap max(false,(n/2)+1);
    for(int a_i = 0;a_i < n;a_i++){
        min.clear();
        max.clear();
        cin >> a[a_i];
        if(a.size()%2 != 0)
            cout << a[a.size()/2];
        else {
            int halfSize = a.size() / 2;
            for(int i = 0;i< a.size()/2;++i){
                max.insert(a[i]);
                min.insert(a[i + halfSize]);
            }
            cout << (min.getRoot() + max.getRoot())/2 << endl; 
        }
    }
    return 0;
}