import java.util.*;
public class Solution {
    static void incNumbers(int n, int start, String cur) {
        if (cur.length() == n) {
            System.out.println(cur);
            return;
        }
        for (int d = start; d <= 9; d++) {
            incNumbers(n, d + 1, cur + d);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 1) System.out.println(0);
            incNumbers(n, 1, "");
        }
    }
}