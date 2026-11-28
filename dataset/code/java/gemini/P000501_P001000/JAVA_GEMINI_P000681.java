import java.util.*;
public class Solution {
    static long sumRec(int n) {
        if (n <= 0) return 0;
        return n + sumRec(n - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            System.out.println(sumRec(n));
        }
    }
}