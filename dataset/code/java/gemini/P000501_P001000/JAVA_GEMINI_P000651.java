import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n - 1; i++) {
                sb.append(vals[i]).append(i == n - 2 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}