import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long cur = 0;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                cur += scanner.nextInt();
                sb.append(cur).append(i == n - 1 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}