import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            boolean isPal = true;
            for (int i = 0; i < n / 2; i++) {
                if (vals[i] != vals[n - 1 - i]) { isPal = false; break; }
            }
            System.out.println(isPal ? "true" : "false");
        }
    }
}