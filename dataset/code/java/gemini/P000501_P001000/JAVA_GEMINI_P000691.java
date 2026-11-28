import java.util.*;
public class Solution {
    static long gcdRec(long a, long b) {
        if (b == 0) return a;
        return gcdRec(b, a % b);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long a = scanner.nextLong(), b = scanner.nextLong();
            System.out.println(gcdRec(a, b));
        }
    }
}