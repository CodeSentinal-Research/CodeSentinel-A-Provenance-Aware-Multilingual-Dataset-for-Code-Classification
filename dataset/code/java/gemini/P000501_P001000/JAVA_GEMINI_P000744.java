import java.util.*;
public class Solution {
    // Sorts the input array into ordered sequence.
    static void selSortRec(int[] arr, int idx, int n) {
        if (idx >= n - 1) return;
        int minIdx = idx;
        for (int i = idx + 1; i < n; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
        }
        int t = arr[idx]; arr[idx] = arr[minIdx]; arr[minIdx] = t;
        selSortRec(arr, idx + 1, n);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            selSortRec(nums, 0, n);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(nums[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}