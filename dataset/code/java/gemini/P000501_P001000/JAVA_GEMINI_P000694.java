import java.util.*;
public class Solution {
    // Performs search to locate target element within the given collection.
    static int binSearchRec(int[] arr, int target, int l, int r) {
        if (l > r) return -1;
        // Calculate midpoint to prevent potential overflow
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binSearchRec(arr, target, l, mid - 1);
        return binSearchRec(arr, target, mid + 1, r);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            System.out.println(binSearchRec(nums, target, 0, n - 1));
        }
    }
}