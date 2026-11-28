#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return vector<int>();

    unordered_map<char, int> p_counts, s_counts;
    for (char c : p) p_counts[c]++;

    vector<int> indices;
    for (int i = 0; i <= s.size() - p.size(); i++) {
        s_counts.clear();
        for (int j = 0; j < p.size(); j++) {
            s_counts[s[i+j]]++;
        }
        if (p_counts == s_counts) indices.push_back(i);
    }

    return indices;
}

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> indices = findAnagrams(s, p);
    for (int i : indices) {
        cout << i << " ";
    }
    return 0;
}
This C++ code uses a sliding window approach to find all occurrences of an anagram in a string. It keeps a window of size equal to the size of the anagram (p) and moves it along the string (s). For each window, it counts the occurrences of each character in the window (s_counts), and if the counts match the counts of the anagram (p_counts), it adds the starting index to the result vector (indices).