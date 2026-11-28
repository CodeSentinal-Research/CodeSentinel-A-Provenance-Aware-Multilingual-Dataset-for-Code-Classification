import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                if (st.isEmpty() || nums[st.peek()] > nums[i]) st.push(i);
            }
            int maxW = 0;
            for (int j = n - 1; j >= 0; j--) {
                while (!st.isEmpty() && nums[st.peek()] <= nums[j]) {
                    maxW = Math.max(maxW, j - st.pop());
                }
            }
            System.out.println(maxW);
        }
    }
}