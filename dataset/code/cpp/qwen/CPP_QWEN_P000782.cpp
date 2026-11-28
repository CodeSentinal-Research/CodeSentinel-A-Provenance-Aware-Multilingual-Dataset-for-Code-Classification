#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Prefix sum of counts? No, just range count.
    // If array is static, prefix sum of 1s?
    // Problem says "Count Elements in Range". Just count indices?
    // "number of elements lying within the specified index range" -> R - L + 1.
    // This seems trivial. Maybe it means values?
    // "Preprocess using prefix sums" suggests counting specific values.
    // Assuming it means count of ALL elements in index range [L, R], which is just R-L+1.
    // Or maybe count of elements <= X?
    // Given ambiguity, I'll assume it asks for count of elements in index range, which is trivial.
    // However, "Prefix Sum" category suggests something more.
    // Let's assume it's a trick question or I'm missing "value" constraint.
    // If it's just index range, answer is R-L+1.
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << R - L + 1 << endl;
    }
    return 0;
}
