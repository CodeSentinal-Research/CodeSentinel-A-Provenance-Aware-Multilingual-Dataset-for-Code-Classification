#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    
    vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    unordered_set<int> complements;
    for(int num : numbers) {
        if(complements.count(target - num)) {
            cout << "Yes" << endl;
            return 0;
        }
        complements.insert(num);
    }
    
    cout << "No" << endl;
    return 0;
}