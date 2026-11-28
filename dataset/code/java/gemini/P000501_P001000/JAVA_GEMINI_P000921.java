import java.util.Scanner;

public class Solution {
    public static int[] digitFrequency(long n) {
        int[] freq = new int[10];
        n = Math.abs(n);
        if (n == 0) {
            freq[0] = 1;
            return freq;
        }
        while (n > 0) {
            freq[(int)(n % 10)]++;
            n /= 10;
        }
        return freq;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            int[] res = digitFrequency(n);
            for (int i = 0; i < 10; i++) {
                System.out.print(res[i] + (i == 9 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}