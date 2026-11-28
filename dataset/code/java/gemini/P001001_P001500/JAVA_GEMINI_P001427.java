public class Solution {
    private int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public int countLargestGroup(int n) {
        int[] groups = new int[40];
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int s = digitSum(i);
            groups[s]++;
            maxSize = Math.max(maxSize, groups[s]);
        }

        int count = 0;
        for (int val : groups) {
            if (val == maxSize) count++;
        }
        return count;
    }
}