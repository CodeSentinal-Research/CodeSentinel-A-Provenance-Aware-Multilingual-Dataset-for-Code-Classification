import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int q = scanner.nextInt();
            while (q-- > 0) {
                int target = scanner.nextInt();
                boolean found = false;
                for (int val : arr) {
                    if (val == target) { found = true; break; }
                }
                System.out.println(found ? "Found" : "Not Found");
            }
        }
    }
}