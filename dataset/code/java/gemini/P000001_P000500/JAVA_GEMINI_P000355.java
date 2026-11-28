import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int x = scanner.nextInt();
            boolean found = false;
            for (int v : arr) if (v == x) { found = true; break; }
            System.out.println(found ? "Present" : "Missing");
        }
    }
}