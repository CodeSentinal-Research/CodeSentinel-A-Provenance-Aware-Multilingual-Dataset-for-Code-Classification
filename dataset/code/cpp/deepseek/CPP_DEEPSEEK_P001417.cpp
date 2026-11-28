Here is the code for the given problem:

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> first(N), second(M);
    unordered_map<int, int> count;

    for (int &num : first) {
        cin >> num;
        count[num]++;
    }

    for (int &num : second) {
        cin >> num;
        count[num]--;
    }

    for (int num : first) {
        if (count[num] > 0) {
            cout << num << " ";
        }
    }

    for (int num : second) {
        if (count[num] > 0) {
            cout << num << " ";
        }
    }

    return 0;
}

This program takes two arrays as input. The first array (`first`) has `N` elements, and the second array (`second`) has `M` elements. The program then counts the number of occurrences of each element in both arrays. The remaining elements of the first array are then printed in their original order, and the remaining elements of the second array are printed in the relative order they appear in the second array.