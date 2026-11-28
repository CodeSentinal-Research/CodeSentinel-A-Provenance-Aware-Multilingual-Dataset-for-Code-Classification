import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt(), k = scanner.nextInt();
            int[] merged = new int[m + n];
            for (int i = 0; i < m + n; i++) merged[i] = scanner.nextInt();
            Arrays.sort(merged);
            System.out.println(merged[k - 1]);
        }
    }
}