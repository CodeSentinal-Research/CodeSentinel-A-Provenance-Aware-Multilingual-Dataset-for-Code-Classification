import java.util.Scanner;

public class Solution {
    public static long modSub(long a, long b, long m) {
        return ((a % m) - (b % m) + m) % m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long m = sc.nextLong();
            System.out.println(modSub(a, b, m));
        }
        sc.close();
    }
}