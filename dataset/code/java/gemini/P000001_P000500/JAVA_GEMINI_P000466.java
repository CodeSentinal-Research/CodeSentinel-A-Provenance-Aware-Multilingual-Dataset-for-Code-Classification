import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
            Arrays.sort(arr);
            boolean found = false;
            for (int i = 0; i < n - 2; i++) {
                int l = i + 1, r = n - 1;
                while (l < r) {
                    int s = arr[i] + arr[l] + arr[r];
                    if (s == target) { found = true; break; }
                    else if (s < target) l++;
                    else r--;
                }
                if (found) break;
            }
            System.out.println(found ? "Yes" : "No");
        }
    }
}