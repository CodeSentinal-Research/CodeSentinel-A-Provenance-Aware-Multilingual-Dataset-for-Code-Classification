import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int[] sorted = nums.clone();
            Arrays.sort(sorted);
            int l = 0, r = n - 1;
            while (l < n && nums[l] == sorted[l]) l++;
            while (r > l && nums[r] == sorted[r]) r--;
            System.out.println(r >= l ? r - l + 1 : 0);
        }
    }
}