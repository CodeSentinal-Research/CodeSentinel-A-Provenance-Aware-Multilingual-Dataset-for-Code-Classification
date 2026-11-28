import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int val = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            sb.append(val);
            for (int i = 0; i < n; i++) sb.append(" ").append(vals[i]);
            System.out.println(sb.toString());
        }
    }
}