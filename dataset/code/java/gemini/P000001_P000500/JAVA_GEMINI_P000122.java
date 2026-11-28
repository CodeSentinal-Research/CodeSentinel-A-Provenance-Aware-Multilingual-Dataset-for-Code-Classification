import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) arr[i] = scanner.nextLong();
            long maxSoFar = arr[0], currMax = arr[0];
            for (int i = 1; i < n; i++) {
                currMax = Math.max(arr[i], currMax + arr[i]);
                maxSoFar = Math.max(maxSoFar, currMax);
            }
            System.out.println(maxSoFar);
        }
    }
}