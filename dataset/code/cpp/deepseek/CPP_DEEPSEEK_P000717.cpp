#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partition(string s, int start, vector<string>& partitions, string partition) {
    if (start >= s.size()) {
        partitions.push_back(partition);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            string part = s.substr(start, end - start + 1);
            partition += part;
            partition(s, end + 1, partitions, partition);
            partition.pop_back();
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> partitions;
    partition(s, 0, partitions, "");

    cout << "All palindrome partitions: ";
    for (string partition : partitions) {
        cout << partition << " ";
    }
    cout << endl;

    return 0;
}