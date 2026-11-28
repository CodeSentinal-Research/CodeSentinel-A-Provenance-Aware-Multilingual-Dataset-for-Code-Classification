#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdint>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <numeric>
#include <sstream>
using namespace std;

#ifndef DATA_STRUCTURES_DEFINED
#define DATA_STRUCTURES_DEFINED
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node {
    int val;
    vector<Node*> children;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
};
#endif

class Solution {
public:
    string removeKdigits(string num, int k) {
        // Stack to store the digits
        stack<char> numStack;
        
        // Iterating through each digit in the number
        for (char digit : num) {
            // While there are remaining removals (k) and the stack is not empty and the current digit is smaller than the top of the stack
            while (k > 0 && !numStack.empty() && digit < numStack.top()) {
                // Remove digits from the stack
                numStack.pop();
                k--;
            }
            // Push the current digit to the stack
            numStack.push(digit);
        }
        
        // After iterating through the number, if there are still remaining removals, remove digits from the stack
        while (k > 0 && !numStack.empty()) {
            numStack.pop();
            k--;
        }

        // Construct the result string by popping digits from the stack
        string temp = "";
        while (!numStack.empty()) {
            temp.push_back(numStack.top());
            numStack.pop();
        }
        // Reverse the result string to get the correct order
        reverse(temp.begin(), temp.end());

        // Remove leading zeros and construct the final result
        int m = temp.size();
        string result = "";
        int foundNonZero = 0;
        for (int i = 0; i < m; i++) {
            if (temp[i] == '0' && foundNonZero == 0) {
                continue;
            } else {
                result.push_back(temp[i]);
                foundNonZero = 1;
            }
        }
        // If the result is empty, return "0"
        if (result.size() == 0)
            result.push_back('0');
        return result;
    }
};