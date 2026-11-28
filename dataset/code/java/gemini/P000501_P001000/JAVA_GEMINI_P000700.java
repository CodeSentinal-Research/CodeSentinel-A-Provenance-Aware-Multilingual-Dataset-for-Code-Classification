import java.util.*;
public class Solution {
    static int maxRec(int[] arr, int idx) {
        if (idx == arr.length - 1) return arr[idx];
        return Math.max(arr[idx], maxRec(arr, idx + 1));
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            System.out.println(maxRec(nums, 0));
        }
    }
}