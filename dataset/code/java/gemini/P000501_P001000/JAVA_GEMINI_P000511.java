import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n], ans = new int[n];
            Arrays.fill(ans, -1);
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < 2 * n; i++) {
                int val = nums[i % n];
                while (!st.isEmpty() && nums[st.peek()] < val) {
                    ans[st.pop()] = val;
                }
                if (i < n) st.push(i);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(ans[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}