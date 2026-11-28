#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string toMorse(char c) {
    vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    return codes[c - 'a'];
}

int main() {
    int n;
    cin >> n;
    unordered_set<string> transformations;
    
    while (n--) {
        string word;
        cin >> word;
        string morse = "";
        for (char c : word) morse += toMorse(c);
        transformations.insert(morse);
    }
    
    cout << transformations.size() << endl;
    return 0;
}
