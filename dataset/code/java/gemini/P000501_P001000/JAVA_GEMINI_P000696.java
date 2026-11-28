import java.util.*;
public class Solution {
    static int lastOccRec(int[] arr, int target, int l, int r, int ans) {
        if (l > r) return ans;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return lastOccRec(arr, target, mid + 1, r, mid);
        if (arr[mid] > target) return lastOccRec(arr, target, l, mid - 1, ans);
        return lastOccRec(arr, target, mid + 1, r, ans);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            System.out.println(lastOccRec(nums, target, 0, n - 1, -1));
        }
    }
}