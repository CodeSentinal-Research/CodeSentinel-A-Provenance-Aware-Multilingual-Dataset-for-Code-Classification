public class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int total = 0;
        for (int x : arr) total += x;
        if (total % 3 != 0) return false;

        int target = total / 3;
        int curSum = 0, count = 0;

        for (int x : arr) {
            curSum += x;
            if (curSum == target) {
                count++;
                curSum = 0;
            }
        }
        return count >= 3;
    }
}