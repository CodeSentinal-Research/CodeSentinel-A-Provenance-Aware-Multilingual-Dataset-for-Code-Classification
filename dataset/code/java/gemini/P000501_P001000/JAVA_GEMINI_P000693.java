import java.util.*;
public class Solution {
    static boolean linSearchRec(int[] arr, int target, int idx) {
        if (idx >= arr.length) return false;
        if (arr[idx] == target) return true;
        return linSearchRec(arr, target, idx + 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            System.out.println(linSearchRec(nums, target, 0) ? "true" : "false");
        }
    }
}