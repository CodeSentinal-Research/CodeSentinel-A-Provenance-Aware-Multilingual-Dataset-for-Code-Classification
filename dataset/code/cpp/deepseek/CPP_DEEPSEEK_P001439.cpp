Here is the complete C++ code for the problem:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    unordered_set<string> uniqueTransforms;

    for(int i = 0; i < n; i++) {
        string word;
        getline(cin, word);
        uniqueTransforms.insert(word);
    }

    cout << uniqueTransforms.size() << endl;

    return 0;
}

This code reads the number of words, then each word. It inserts each word into a hash set (unordered_set), which automatically removes any duplicates. The size of the hash set is then the number of unique words.