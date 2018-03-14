#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_balanced(string expression) {
    stack<char> tracker;
    for(char c: expression){
        if(c == '{')
            tracker.push('}');
        else if(c == '[')
            tracker.push(']');
        else if(c == '(')
            tracker.push(')');
        else {
            if(tracker.empty() || tracker.top() != c)
                return false;
            tracker.pop();
        }
    }
    return tracker.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}