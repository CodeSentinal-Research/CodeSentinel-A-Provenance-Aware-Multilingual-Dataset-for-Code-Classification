import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long[] arr = new long[n];
            long baseSum = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextLong();
                baseSum += (long) i * arr[i];
            }

            long maxSum = baseSum;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long gain = (long) (j - i) * arr[i] + (long) (i - j) * arr[j];
                    maxSum = Math.max(maxSum, baseSum + gain);
                }
            }
            System.out.println(maxSum);
        }
        sc.close();
    }
}