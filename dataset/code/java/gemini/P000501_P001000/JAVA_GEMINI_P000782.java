import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int q = scanner.nextInt();
            while (q-- > 0) {
                int l = scanner.nextInt(), r = scanner.nextInt();
                System.out.println(r - l + 1);
            }
        }
    }
}