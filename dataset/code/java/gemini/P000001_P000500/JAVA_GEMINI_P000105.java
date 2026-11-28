import java.util.Scanner;

public class Solution {
    public static int[] countEvenOdd(int[] arr) {
        int even = 0, odd = 0;
        for (int x : arr) {
            if (x % 2 == 0) even++;
            else odd++;
        }
        return new int[]{even, odd};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            int[] res = countEvenOdd(arr);
            System.out.println("Even: " + res[0] + ", Odd: " + res[1]);
        }
        sc.close();
    }
}