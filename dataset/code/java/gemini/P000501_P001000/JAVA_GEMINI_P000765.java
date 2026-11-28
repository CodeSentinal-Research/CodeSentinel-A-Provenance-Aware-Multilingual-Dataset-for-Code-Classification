import java.util.*;
public class Solution {
    static boolean isMaxHeap(int[] arr, int idx) {
        int n = arr.length;
        int l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < n) {
            if (arr[idx] < arr[l] || !isMaxHeap(arr, l)) return false;
        }
        if (r < n) {
            if (arr[idx] < arr[r] || !isMaxHeap(arr, r)) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            System.out.println(isMaxHeap(nums, 0) ? "true" : "false");
        }
    }
}