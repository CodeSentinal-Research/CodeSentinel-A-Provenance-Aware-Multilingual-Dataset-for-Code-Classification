import java.util.Scanner;

public class Solution {
    private static long gcd(long a, long b) {
        while (b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    private static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public static long arrayLcm(int[] arr) {
        long res = arr[0];
        for (int i = 1; i < arr.length; i++) {
            res = lcm(res, arr[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(arrayLcm(arr));
        }
        sc.close();
    }
}