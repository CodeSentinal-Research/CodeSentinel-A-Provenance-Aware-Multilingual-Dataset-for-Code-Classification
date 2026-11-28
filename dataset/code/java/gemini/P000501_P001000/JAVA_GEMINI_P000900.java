import java.util.Scanner;

public class Solution {
    public static boolean isDivisibleBy9(String s) {
        int sum = 0;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) sum += (c - '0');
        }
        return sum % 9 == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            System.out.println(isDivisibleBy9(s) ? "YES" : "NO");
        }
        sc.close();
    }
}