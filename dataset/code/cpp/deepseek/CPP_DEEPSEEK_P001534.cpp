Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n <= 2) return n;
    
    int i = 0, j = 1, maxLen = 1;
    unordered_map<char, int> index;
    index[s[i]] = i;
    
    while(j < n){
        if(index.find(s[j]) == index.end()){
            index[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else{
            i = max(i, index[s[j]] + 1);
            index[s[j]] = j;
            j++;
        }
    }
    
    return maxLen;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
In this code, we maintain two pointers `i` and `j`, and an unordered_map `index`. `i` and `j` are the left and right pointers, `index` is a map to store the last index of each character. If the character at `j` (the current character) is not in `index`, we add it and update the maximum length. If the character is in `index`, it means it forms a substring that has at most two distinct characters and we update `i` to be the maximum of `i` and the index of `s[j]` (the character at `j`).

The time complexity of the solution is O(n) as we only traverse the string once. The space complexity is also O(n) due to the usage of the unordered_map.