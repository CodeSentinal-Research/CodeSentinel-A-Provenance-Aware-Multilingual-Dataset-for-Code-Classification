import java.util.*;
public class Solution {
    // Sorts the input array into ordered sequence.
    static void quickSort(int[] arr, int l, int r) {
        if (l >= r) return;
        int pivot = arr[r], pIdx = l;
        for (int i = l; i < r; i++) {
            if (arr[i] < pivot) {
                int t = arr[i]; arr[i] = arr[pIdx]; arr[pIdx] = t;
                pIdx++;
            }
        }
        int t = arr[pIdx]; arr[pIdx] = arr[r]; arr[r] = t;
        quickSort(arr, l, pIdx - 1);
        quickSort(arr, pIdx + 1, r);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            quickSort(nums, 0, n - 1);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(nums[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}