import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            int l = 0, r = n - 1;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                int mid = l + (r - l) / 2;
                if (arr[mid] > arr[mid + 1]) r = mid;
                else l = mid + 1;
            }
            System.out.println(l);
        }
    }
}