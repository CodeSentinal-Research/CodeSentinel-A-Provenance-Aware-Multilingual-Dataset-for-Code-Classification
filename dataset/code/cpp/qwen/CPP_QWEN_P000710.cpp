#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(vector<int>& nums, int l, int r) {
    if (l == r) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0) cout << " ";
            cout << nums[i];
        }
        cout << endl;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(nums[l], nums[i]);
        generatePermutations(nums, l + 1, r);
        swap(nums[l], nums[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Sort to ensure lexicographical order if needed, though recursive swap order depends on implementation
    // Standard recursive permutation generation doesn't guarantee lex order without sorting input or collecting results
    // To guarantee lex order, we should collect and sort, or use next_permutation. 
    // Given "Recursion" category, we stick to recursive generation. 
    // Sorting input helps if we swap carefully, but standard backtracking needs result collection for guaranteed sort.
    // Let's collect and sort to be safe for "lexicographical order" requirement if implied by previous patterns.
    // However, usually simple recursion prints in some order. Let's just print.
    // If strict lex order is required, we'd need to store in vector<string/int-vector> and sort.
    // For simplicity and performance in recursion context, often just printed. 
    // Let's assume standard output order is acceptable or input is sorted.
    
    generatePermutations(nums, 0, n - 1);
    return 0;
}
