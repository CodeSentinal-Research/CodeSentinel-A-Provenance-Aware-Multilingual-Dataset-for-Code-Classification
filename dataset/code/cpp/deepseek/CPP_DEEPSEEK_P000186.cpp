#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int maxLength = 0;
    int currentLength = 1;
    int maxProduct = 1;
    int currentProduct = 1;

    for (int i = 0; i < N; i++) {
        if (nums[i] > 0) {
            currentProduct *= nums[i];
            currentLength++;
        } else {
            if (currentProduct > 0) {
                maxProduct = max(maxProduct, currentProduct);
            }

            currentProduct = nums[i];
            currentLength = 1;
        }

        maxProduct = max(maxProduct, currentProduct);
    }

    if (currentProduct > 0) {
        maxProduct = max(maxProduct, currentProduct);
    }

    cout << maxProduct << endl;

    return 0;
}