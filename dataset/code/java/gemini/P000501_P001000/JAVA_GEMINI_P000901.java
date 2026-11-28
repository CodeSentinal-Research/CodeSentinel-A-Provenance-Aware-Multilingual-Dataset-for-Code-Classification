import java.util.Scanner;

public class Solution {
    public static boolean isDivisibleBy11(String s) {
        int oddSum = 0, evenSum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) oddSum += (s.charAt(i) - '0');
            else evenSum += (s.charAt(i) - '0');
        }
        return Math.abs(oddSum - evenSum) % 11 == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            System.out.println(isDivisibleBy11(s) ? "YES" : "NO");
        }
        sc.close();
    }
}