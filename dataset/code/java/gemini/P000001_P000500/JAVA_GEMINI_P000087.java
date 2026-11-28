import java.util.Scanner;

public class Solution {
    public static long sumOfNaturalNumbers(long n) {
        if (n < 0) return 0;
        return (n * (n + 1)) / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            System.out.println(sumOfNaturalNumbers(n));
        }
        sc.close();
    }
}