import java.util.Arrays;

public class Solution {
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int left = 1, right = position[position.length - 1] - position[0];
        int ans = 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int count = 1, last = position[0];
            for (int i = 1; i < position.length; i++) {
                if (position[i] - last >= mid) {
                    count++;
                    last = position[i];
                }
            }
            if (count >= m) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
}