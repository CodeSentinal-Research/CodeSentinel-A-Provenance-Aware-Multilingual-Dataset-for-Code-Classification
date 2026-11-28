#include <vector>

class Solution {
public:
    int rowWithMax1s(std::vector<std::vector<int>>& arr, int n, int m) {
        int r = 0, c = m - 1;
        int maxRow = -1;

        while (r < n && c >= 0) {
            if (arr[r][c] == 1) {
                maxRow = r;
                c--;
            } else {
                r++;
            }
        }
        return maxRow;
    }
};