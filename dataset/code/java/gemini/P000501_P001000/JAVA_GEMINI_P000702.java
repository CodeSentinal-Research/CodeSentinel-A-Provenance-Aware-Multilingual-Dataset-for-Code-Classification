import java.util.*;
public class Solution {
    static int countOccRec(int[] arr, int target, int idx) {
        if (idx >= arr.length) return 0;
        return (arr[idx] == target ? 1 : 0) + countOccRec(arr, target, idx + 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            System.out.println(countOccRec(nums, target, 0));
        }
    }
}