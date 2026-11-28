import java.util.Scanner;

public class Solution {
    public static long frobeniusNumber(long a, long b) {
        return a * b - a - b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            System.out.println(frobeniusNumber(a, b));
        }
        sc.close();
    }
}