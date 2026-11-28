import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int left = scanner.nextInt() - 1, right = scanner.nextInt() - 1;
            // Binary search loop to narrow down range
            while (left < right) {
                int tmp = vals[left]; vals[left] = vals[right]; vals[right] = tmp;
                left++; right--;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}