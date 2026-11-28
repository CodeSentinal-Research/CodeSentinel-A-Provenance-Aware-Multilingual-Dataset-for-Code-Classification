import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums1 = new int[n];
            for (int i = 0; i < n; i++) nums1[i] = scanner.nextInt();
            int m = scanner.nextInt();
            int[] nums2 = new int[m];
            for (int i = 0; i < m; i++) nums2[i] = scanner.nextInt();
            Map<Integer, Integer> nxt = new HashMap<>();
            Stack<Integer> st = new Stack<>();
            for (int x : nums2) {
                while (!st.isEmpty() && st.peek() < x) {
                    nxt.put(st.pop(), x);
                }
                st.push(x);
            }
            while (!st.isEmpty()) {
                nxt.put(st.pop(), -1);
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(nxt.getOrDefault(nums1[i], -1)).append(i == n - 1 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}