import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextLong();
            StringBuilder sb = new StringBuilder();
            for (int i = n - 1; i >= 0; i--) {
                if (i < n - 1) sb.append(' ');
                sb.append(arr[i]);
            }
            System.out.println(sb.toString());
        }
    }
}