class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        long long left = 1, right = num;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long long mid = left + (right - left) / 2;
            long long sq = mid * mid;
            if (sq == num) return true;
            else if (sq < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};