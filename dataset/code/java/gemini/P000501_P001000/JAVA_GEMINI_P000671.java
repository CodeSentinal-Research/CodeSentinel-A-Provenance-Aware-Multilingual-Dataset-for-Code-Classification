import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            boolean sorted = true;
            for (int i = 1; i < n; i++) {
                if (vals[i] < vals[i - 1]) { sorted = false; break; }
            }
            System.out.println(sorted ? "true" : "false");
        }
    }
}