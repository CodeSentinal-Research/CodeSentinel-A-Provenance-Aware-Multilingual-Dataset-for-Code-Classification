import java.util.Scanner;

public class Solution {
    // Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
    private static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Computes the Greatest Common Divisor (GCD) using Euclidean algorithm.
    public static int arrayGcd(int[] arr) {
        int res = arr[0];
        for (int i = 1; i < arr.length; i++) {
            res = gcd(res, arr[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(arrayGcd(arr));
        }
        sc.close();
    }
}