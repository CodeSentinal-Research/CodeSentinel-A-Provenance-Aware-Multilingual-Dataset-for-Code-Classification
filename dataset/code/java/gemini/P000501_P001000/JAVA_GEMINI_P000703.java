import java.util.*;
public class Solution {
    static boolean isPal(int[] arr, int l, int r) {
        if (l >= r) return true;
        if (arr[l] != arr[r]) return false;
        return isPal(arr, l + 1, r - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            System.out.println(isPal(nums, 0, n - 1) ? "true" : "false");
        }
    }
}