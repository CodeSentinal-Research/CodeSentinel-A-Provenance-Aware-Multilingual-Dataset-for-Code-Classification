import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int idx = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (arr[i] == target) { idx = i; break; }
            }
            System.out.println(idx);
        }
    }
}