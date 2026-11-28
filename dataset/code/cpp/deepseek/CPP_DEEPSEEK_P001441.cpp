#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    unordered_set<int> numbers;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.insert(num);
    }

    long long count = 0;
    for(int num : numbers) {
        if(numbers.find(num + k) != numbers.end()) {
            count++;
        }
        if(numbers.find(num - k) != numbers.end()) {
            count++;
        }
    }

    cout << count / 2 << endl;

    return 0;
}