import java.util.*;
public class Solution {
    // Sorts the input array into ordered sequence.
    static void bubbleSortRec(int[] arr, int n) {
        if (n <= 1) return;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = t;
            }
        }
        bubbleSortRec(arr, n - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            bubbleSortRec(nums, n);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(nums[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}