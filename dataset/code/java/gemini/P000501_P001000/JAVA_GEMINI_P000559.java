import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] q = new int[n];
            for (int i = 0; i < n; i++) q[i] = scanner.nextInt();
            int k = scanner.nextInt();
            int l = 0, r = k - 1;
            while (l < r) {
                int temp = q[l]; q[l] = q[r]; q[r] = temp;
                l++; r--;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(q[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}