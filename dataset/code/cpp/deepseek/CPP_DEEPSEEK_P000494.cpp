#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> result(T.size(), 0);
    stack<int> s;

    for(int i = 0; i < T.size(); ++i){
        while(!s.empty() && T[s.top()] < T[i]){
            result[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main(){
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(T);

    for(int i : result)
        cout << i << " ";

    return 0;
}