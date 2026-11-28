import java.util.*;
public class Solution {
    static void revArrRec(int[] arr, int l, int r) {
        if (l >= r) return;
        int tmp = arr[l]; arr[l] = arr[r]; arr[r] = tmp;
        revArrRec(arr, l + 1, r - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            revArrRec(nums, 0, n - 1);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(nums[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}