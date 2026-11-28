import java.util.*;

public class Solution {
    public List<Integer> subarraySum(int[] arr, int target) {
        int l = 0;
        long curSum = 0;
        for (int r = 0; r < arr.length; r++) {
            curSum += arr[r];
            while (curSum > target && l < r) {
                curSum -= arr[l++];
            }
            if (curSum == target) {
                return Arrays.asList(l + 1, r + 1);
            }
        }
        return Arrays.asList(-1);
    }
}