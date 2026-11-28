Here's the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int longestWPI(vector<int>& hours) {
    int n = hours.size();
    int res = 0;
    for(int i = 0; i < n; i++){
        if(hours[i] > 8){
            hours[i] = 1000000000;
        }
    }

    for(int i = 0; i < n; i++){
        if(hours[i] == 1000000000){
            continue;
        }

        int count = 0;
        for(int j = i; j < n; j++){
            if(hours[j] > hours[i]){
                count++;
            }
            else{
                break;
            }
        }

        for(int j = i; j < n; j++){
            if(hours[j] == hours[i]){
                count++;
            }
            else{
                break;
            }
        }

        if(count > res){
            res = count;
        }
    }

    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> hours(n);
    for(int i = 0; i < n; i++){
        cin >> hours[i];
    }

    cout << longestWPI(hours) << "\n";

    return 0;
}

This code works by first marking all instances of workdays in the hours array with a high value, and then checking for the longest sequence of workdays where the number of non-workdays is strictly greater.