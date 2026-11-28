import java.util.Scanner;

public class Solution {
    public static long countDivisibleInRange(long l, long r, long k) {
        return (r / k) - ((l - 1) / k);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long l = sc.nextLong();
            long r = sc.nextLong();
            long k = sc.nextLong();
            System.out.println(countDivisibleInRange(l, r, k));
        }
        sc.close();
    }
}