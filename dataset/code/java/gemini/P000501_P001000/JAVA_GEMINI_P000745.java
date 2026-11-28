import java.util.*;
public class Solution {
    // Sorts the input array into ordered sequence.
    static void insSortRec(int[] arr, int n) {
        if (n <= 1) return;
        insSortRec(arr, n - 1);
        int last = arr[n - 1];
        int j = n - 2;
        while (j >= 0 && arr[j] > last) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            insSortRec(nums, n);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(nums[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}