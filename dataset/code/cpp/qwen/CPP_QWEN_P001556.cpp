#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;
    
    vector<int> pCount(26, 0);
    vector<int> tCount(26, 0);
    
    for (char c : pattern) pCount[c - 'a']++;
    
    int count = 0;
    int left = 0;
    
    for (int right = 0; right < text.length(); ++right) {
        tCount[text[right] - 'a']++;
        
        if (right >= pattern.length()) {
            tCount[text[left] - 'a']--;
            left++;
        }
        
        if (tCount == pCount) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}
