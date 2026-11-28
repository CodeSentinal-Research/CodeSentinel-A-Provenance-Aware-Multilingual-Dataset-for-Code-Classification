import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextLong();
            StringBuilder sb = new StringBuilder();
            sb.append(arr[n - 1]);
            for (int i = 0; i < n - 1; i++) {
                sb.append(' ').append(arr[i]);
            }
            System.out.println(sb.toString());
        }
    }
}