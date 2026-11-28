#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string dna;
    cin >> dna;
    
    unordered_set<string> sequences;
    for (int i = 0; i < dna.size() - 9; i++) {
        string sequence = dna.substr(i, 10);
        if (sequences.count(sequence)) {
            sequences.insert(sequence);
        }
    }
    
    vector<string> result(sequences.begin(), sequences.end());
    sort(result.begin(), result.end());
    
    for (const auto &sequence : result) {
        cout << sequence << endl;
    }
    
    return 0;
}