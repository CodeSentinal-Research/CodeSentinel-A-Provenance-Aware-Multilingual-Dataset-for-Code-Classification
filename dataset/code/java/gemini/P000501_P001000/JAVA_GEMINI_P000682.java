import java.util.*;
public class Solution {
    static long factRec(int n) {
        if (n <= 1) return 1;
        return n * factRec(n - 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            System.out.println(factRec(n));
        }
    }
}