#include <vector>
#include <iostream>

using namespace std;

void query1(vector<vector<int>>& seqList,int x,int y, int lastAnswer){
    int index = (x^lastAnswer) % seqList.size();
    seqList[index].push_back(y);
}

void query2(vector<vector<int>>& seqList,int x, int y,int& lastAnswer){
    int index = (x^lastAnswer) % seqList.size();
    int seqIndex = y%seqList[index].size();
    lastAnswer = seqList[index][seqIndex];
    cout << lastAnswer<< endl;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> seqList(n, vector<int>(0));
    int lastAnswer = 0;
    
    for(int i = 0;i<q;i++){
        int type,x,y;
        cin >> type >> x >> y;
        if(type == 1)
            query1(seqList,x,y,lastAnswer);
        else if(type == 2)
            query2(seqList,x,y,lastAnswer);
    }
    return 0;
}
